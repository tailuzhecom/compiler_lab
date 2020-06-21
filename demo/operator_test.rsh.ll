; ModuleID = 'rush'
source_filename = "rush"

declare i32 @printf(i8*, ...)

define i32 @main() {
entry:
  %a = alloca i32
  store i32 1, i32* %a
  %b = alloca float
  store float 2.000000e+00, float* %b
  %0 = load i32, i32* %a
  %1 = load i32, i32* %a
  %2 = mul i32 %1, %0
  %3 = load i32, i32* %a
  %4 = load i32, i32* %a
  %5 = add i32 %4, %3
  %6 = load i32, i32* %a
  %7 = load i32, i32* %a
  %8 = sub i32 %7, %6
  %9 = load float, float* %b
  %10 = load float, float* %b
  %11 = fdiv float %10, %9
  %12 = load i32, i32* %a
  %13 = load i32, i32* %a
  %14 = fdiv i32 %13, %12
  %15 = load i32, i32* %a
  %16 = load i32, i32* %a
  %17 = icmp eq i32 %16, %15
  %18 = load i32, i32* %a
  %19 = xor i32 %18, -1
  %20 = load i32, i32* %a
  %21 = sub i32 0, %20
  ret i32 0
}
