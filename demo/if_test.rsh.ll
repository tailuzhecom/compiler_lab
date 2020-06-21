; ModuleID = 'rush'
source_filename = "rush"

declare i32 @printf(i8*, ...)

define i32 @main() {
entry:
  %a = alloca i32
  store i32 1, i32* %a
  %0 = load i32, i32* %a
  %1 = icmp eq i32 %0, 1
  br i1 %1, label %then, label %else

then:                                             ; preds = %entry
  store i32 2, i32* %a
  br label %merge

else:                                             ; preds = %entry
  store i32 3, i32* %a
  br label %merge

merge:                                            ; preds = %else, %then
  %phi_val = phi i32 [ 1, %then ], [ 1, %else ]
  ret i32 0
}
