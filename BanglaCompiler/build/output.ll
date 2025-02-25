; ModuleID = 'BanglaModule'
source_filename = "BanglaModule"

@0 = private unnamed_addr constant [8 x i8] c"\E0\A7\A7\E0\A7\A6\0A\00", align 1
@1 = private unnamed_addr constant [5 x i8] c"\E0\A7\AB\0A\00", align 1

declare i32 @printf(ptr, ...)

define i32 @main() {
entry:
  %"\E0\A6\95" = alloca i32, align 4
  store i32 10, ptr %"\E0\A6\95", align 4
  %0 = load i32, ptr %"\E0\A6\95", align 4
  %1 = icmp sgt i32 %0, 5
  br i1 %1, label %then, label %else

then:                                             ; preds = %entry
  %2 = load i32, ptr %"\E0\A6\95", align 4
  %3 = call i32 (ptr, ...) @printf(ptr @0)
  br label %merge

else:                                             ; preds = %entry
  %4 = call i32 (ptr, ...) @printf(ptr @1)
  br label %merge

merge:                                            ; preds = %else, %then
  ret i32 0
}
