; ModuleID = 'output.ll'
source_filename = "BanglaModule"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-i128:128-f80:128-n8:16:32:64-S128"
target triple = "x86_64-redhat-linux-gnu"

declare i32 @printf(ptr, ...)

define i32 @main() {
entry:
  %"\E0\A6\95" = alloca i32, align 4
  store i32 10, ptr %"\E0\A6\95", align 4
  ret i32 0
}
