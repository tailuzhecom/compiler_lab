; ModuleID = 'rush'
source_filename = "rush"

declare i32 @printf(i8*, ...)

define i32 @main() {
entry:
  %a = alloca i32
  store i32 10, i32* %a
  %b = alloca i32
  %0 = load i32, i32* %a
  %1 = mul i32 2, %0
  store i32 %1, i32* %b
  ret i32 0
}
