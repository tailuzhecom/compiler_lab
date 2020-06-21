; ModuleID = 'rush'
source_filename = "rush"

declare i32 @printf(i8*, ...)

define i32 @main() {
entry:
  %a = alloca i32
  %b = alloca i32
  store i32 2, i32* %b
  %c = alloca i32
  %d = alloca i32
  store i32 1, i32* %d
  %e = alloca i32
  %f = alloca i32
  store i32 1, i32* %f
  %g = alloca i32
  store i32 1, i32* %g
  %h = alloca i32
  ret i32 0
}
