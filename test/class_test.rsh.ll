; ModuleID = 'rush'
source_filename = "rush"

%A = type { i32, i32 }

@0 = private unnamed_addr constant [7 x i8] c"%d    \00"

declare i32 @printf(i8*, ...)

define i32 @main() {
entry:
  %a = alloca %A
  %0 = getelementptr %A, %A* %a, i32 0, i32 0
  store i32 1, i32* %0
  %1 = getelementptr %A, %A* %a, i32 0, i32 1
  store i32 1, i32* %1
  %c = alloca i32
  %2 = getelementptr %A, %A* %a, i32 0, i32 1
  %3 = load i32, i32* %2
  %4 = getelementptr %A, %A* %a, i32 0, i32 0
  %5 = load i32, i32* %4
  %6 = add i32 %5, %3
  store i32 %6, i32* %c
  %7 = load i32, i32* %c
  %8 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([7 x i8], [7 x i8]* @0, i32 0, i32 0), i32 %7)
  ret i32 0
}
