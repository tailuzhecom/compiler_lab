; ModuleID = 'rush'
source_filename = "rush"

@0 = private unnamed_addr constant [3 x i8] c"%d\00"

declare i32 @printf(i8*, ...)

define i32 @add(i32, i32) {
entry:
  %a = alloca i32
  store i32 %0, i32* %a
  %b = alloca i32
  store i32 %1, i32* %b
  %2 = load i32, i32* %b
  %3 = load i32, i32* %a
  %4 = add i32 %3, %2
  ret i32 %4
}

define i32 @main() {
entry:
  %d = alloca i32
  %0 = call i32 @add(i32 1, i32 2)
  store i32 %0, i32* %d
  %1 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @0, i32 0, i32 0))
  ret i32 0
}
