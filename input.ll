; ModuleID = 'rush'
source_filename = "rush"

%A = type { i32, i32 }

@0 = private unnamed_addr constant [4 x i8] c"%d \00"

declare i32 @printf(i8*, ...)

define i32 @main() {
entry:
  %a = alloca i32
  store i32 1, i32* %a
  %b = alloca i32
  store i32 2, i32* %b
  %c = alloca %A
  %0 = getelementptr %A, %A* %c, i32 0, i32 0
  store i32 1, i32* %0
  %1 = load i32, i32* %a
  %2 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @0, i32 0, i32 0), i32 %1)
  ret i32 0
}
