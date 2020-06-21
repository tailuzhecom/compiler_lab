; ModuleID = 'rush'
source_filename = "rush"

@0 = private unnamed_addr constant [3 x i8] c"%d\00"

declare i32 @printf(i8*, ...)

define i32 @main() {
entry:
  %a = alloca i32
  store i32 0, i32* %a
  br label %cond

cond:                                             ; preds = %body, %entry
  %0 = load i32, i32* %a
  %1 = icmp slt i32 %0, 5
  br i1 %1, label %body, label %4

body:                                             ; preds = %cond
  %2 = load i32, i32* %a
  %3 = add i32 %2, 1
  store i32 %3, i32* %a
  br label %cond

; <label>:4:                                      ; preds = %cond
  %5 = load i32, i32* %a
  %6 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @0, i32 0, i32 0), i32 %5)
  ret i32 0
}
