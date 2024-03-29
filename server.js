const express = require('express');
const bodyParser = require('body-parser');
const { exec, spawn } = require('child_process');
const fs = require('fs');
const path = require('path');

const app = express();
const port = 3000;

let compilationProcess;

app.use(bodyParser.json());

app.get('/', (req, res) => {
    res.sendFile(path.join(__dirname, 'index.html'));
});

app.post('/compile', (req, res) => {
    const { code } = req.body;

    fs.writeFile('temp.cpp', code, (err) => {
        if (err) {
            console.error(`Error writing file: ${err}`);
            res.status(500).send('Internal server error');
            return;
        }

        compilationProcess = exec('g++ temp.cpp -o temp.out', (error, stdout, stderr) => {
            if (error) {
                console.error(`Compilation error: ${stderr}`);
                res.status(500).send('Compilation error');
                cleanup();
                return;
            }

            const executionProcess = spawn('./temp.out');

            executionProcess.stdout.on('data', (data) => {
                res.send(data.toString());
            });

            executionProcess.stderr.on('data', (data) => {
                console.error(`Execution error: ${data}`);
                res.status(500).send('Execution error');
            });

            executionProcess.on('close', () => {
                cleanup();
            });
        });
    });
});

app.post('/stop', (req, res) => {
    if (compilationProcess && !compilationProcess.killed) {
        compilationProcess.kill();
        cleanup();
        res.send('Compilation process stopped');
    } else {
        res.status(400).send('No compilation process running');
    }
});

function cleanup() {
    fs.unlink('temp.cpp', (err) => {
        if (err) {
            console.error(`Error deleting temp.cpp: ${err}`);
        }
    });

    fs.unlink('temp.out', (err) => {
        if (err) {
            console.error(`Error deleting temp.out: ${err}`);
        }
    });
}

app.listen(port, () => {
    console.log(`Server is running on port ${port}`);
});