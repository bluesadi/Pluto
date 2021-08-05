; ModuleID = 'IR/TestProgram_orig.ll'
source_filename = "TestProgram.cpp"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-unknown-linux-gnu"

@input = dso_local global [100 x i8] zeroinitializer, align 16
@enc = dso_local global <{ [22 x i8], [78 x i8] }> <{ [22 x i8] c"\86\8A}\87\93\8BM\81\80\8AC\7FII\86q\7FbSi(\9D", [78 x i8] zeroinitializer }>, align 16
@.str = private unnamed_addr constant [25 x i8] c"Please input your flag: \00", align 1
@.str.1 = private unnamed_addr constant [3 x i8] c"%s\00", align 1
@.str.2 = private unnamed_addr constant [18 x i8] c"Congratulations~\0A\00", align 1
@.str.3 = private unnamed_addr constant [18 x i8] c"Sorry try again.\0A\00", align 1

; Function Attrs: noinline nounwind optnone uwtable mustprogress
define dso_local void @_Z7encryptPhPc(i8* %dest, i8* %src) #0 {
entry:
  %dest.addr = alloca i8*, align 8
  %src.addr = alloca i8*, align 8
  %len = alloca i32, align 4
  %i = alloca i32, align 4
  store i8* %dest, i8** %dest.addr, align 8
  store i8* %src, i8** %src.addr, align 8
  %0 = load i8*, i8** %src.addr, align 8
  %call = call i64 @strlen(i8* %0) #5
  %conv = trunc i64 %call to i32
  store i32 %conv, i32* %len, align 4
  store i32 0, i32* %i, align 4
  br label %for.cond

for.cond:                                         ; preds = %for.inc, %entry
  %1 = load i32, i32* %i, align 4
  %2 = load i32, i32* %len, align 4
  %cmp = icmp slt i32 %1, %2
  br i1 %cmp, label %for.body, label %for.end

for.body:                                         ; preds = %for.cond
  %3 = load i8*, i8** %src.addr, align 8
  %4 = load i32, i32* %i, align 4
  %idxprom = sext i32 %4 to i64
  %arrayidx = getelementptr inbounds i8, i8* %3, i64 %idxprom
  %5 = load i8, i8* %arrayidx, align 1
  %conv1 = sext i8 %5 to i32
  %6 = load i32, i32* %i, align 4
  %7 = add i32 32, 1122565374
  %8 = add i32 %7, 2091501629
  %9 = sub i32 %8, 1122565374
  %10 = sub i32 %9, 779637899
  %11 = sub i32 %10, %6
  %12 = add i32 %11, 779637899
  %13 = sub i32 %12, 1741987345
  %14 = sub i32 %13, 2091501629
  %15 = add i32 %14, 1741987345
  %16 = sub i32 %conv1, 392498039
  %17 = sub i32 %16, 1084615141
  %18 = add i32 %17, 392498039
  %19 = sub i32 0, %18
  %20 = sub i32 0, %15
  %21 = add i32 %19, %20
  %22 = sub i32 0, %21
  %23 = sub i32 %22, 1003938404
  %24 = add i32 %23, 1084615141
  %25 = add i32 %24, 1003938404
  %26 = load i32, i32* %i, align 4
  %27 = xor i32 %25, -1
  %28 = and i32 %27, 665112385
  %29 = xor i32 665112385, -1
  %30 = and i32 %25, %29
  %31 = or i32 %28, %30
  %32 = xor i32 -1, -1
  %33 = and i32 %32, 665112385
  %34 = xor i32 665112385, -1
  %35 = and i32 -1, %34
  %36 = or i32 %33, %35
  %37 = xor i32 %31, %36
  %38 = xor i32 %26, -1
  %39 = xor i32 %37, %38
  %40 = and i32 %39, %37
  %41 = xor i32 %26, -1
  %42 = and i32 %41, -1
  %43 = xor i32 -1, -1
  %44 = and i32 %26, %43
  %45 = or i32 %42, %44
  %46 = xor i32 %25, -1
  %47 = xor i32 %45, -1
  %48 = or i32 %46, %47
  %49 = xor i32 %48, -1
  %50 = xor i32 131359636, -1
  %51 = or i32 131359636, %50
  %52 = and i32 %49, %51
  %53 = xor i32 %40, -1
  %54 = xor i32 %52, -1
  %55 = and i32 %53, %54
  %56 = xor i32 %55, -1
  %57 = xor i32 937639726, -1
  %58 = or i32 937639726, %57
  %59 = and i32 %56, %58
  %conv2 = trunc i32 %59 to i8
  %60 = load i8*, i8** %dest.addr, align 8
  %61 = load i32, i32* %i, align 4
  %idxprom3 = sext i32 %61 to i64
  %arrayidx4 = getelementptr inbounds i8, i8* %60, i64 %idxprom3
  store i8 %conv2, i8* %arrayidx4, align 1
  br label %for.inc

for.inc:                                          ; preds = %for.body
  %62 = load i32, i32* %i, align 4
  %63 = add i32 %62, 182527464
  %64 = sub i32 %63, 828953214
  %65 = sub i32 %64, 182527464
  %66 = sub i32 0, %65
  %67 = sub i32 0, 1
  %68 = add i32 %66, %67
  %69 = sub i32 0, %68
  %70 = sub i32 0, 828953214
  %71 = sub i32 %69, %70
  store i32 %71, i32* %i, align 4
  br label %for.cond, !llvm.loop !2

for.end:                                          ; preds = %for.cond
  ret void
}

; Function Attrs: nounwind readonly willreturn
declare dso_local i64 @strlen(i8*) #1

; Function Attrs: noinline norecurse optnone uwtable mustprogress
define dso_local i32 @main() #2 {
entry:
  %retval = alloca i32, align 4
  %dest = alloca [100 x i8], align 16
  %result = alloca i8, align 1
  store i32 0, i32* %retval, align 4
  %call = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([25 x i8], [25 x i8]* @.str, i64 0, i64 0))
  %call1 = call i32 (i8*, ...) @scanf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @.str.1, i64 0, i64 0), i8* getelementptr inbounds ([100 x i8], [100 x i8]* @input, i64 0, i64 0))
  %0 = bitcast [100 x i8]* %dest to i8*
  call void @llvm.memset.p0i8.i64(i8* align 16 %0, i8 0, i64 100, i1 false)
  %arraydecay = getelementptr inbounds [100 x i8], [100 x i8]* %dest, i64 0, i64 0
  call void @_Z7encryptPhPc(i8* %arraydecay, i8* getelementptr inbounds ([100 x i8], [100 x i8]* @input, i64 0, i64 0))
  %call2 = call i64 @strlen(i8* getelementptr inbounds ([100 x i8], [100 x i8]* @input, i64 0, i64 0)) #5
  %cmp = icmp eq i64 %call2, 22
  br i1 %cmp, label %land.rhs, label %land.end

land.rhs:                                         ; preds = %entry
  %arraydecay3 = getelementptr inbounds [100 x i8], [100 x i8]* %dest, i64 0, i64 0
  %call4 = call i32 @memcmp(i8* %arraydecay3, i8* getelementptr inbounds ([100 x i8], [100 x i8]* bitcast (<{ [22 x i8], [78 x i8] }>* @enc to [100 x i8]*), i64 0, i64 0), i64 22) #5
  %tobool = icmp ne i32 %call4, 0
  %1 = xor i1 %tobool, true
  %2 = and i1 %1, true
  %3 = xor i1 true, true
  %4 = and i1 %tobool, %3
  %5 = or i1 %2, %4
  %6 = xor i1 true, true
  %7 = and i1 %6, true
  %8 = xor i1 true, true
  %9 = and i1 true, %8
  %10 = or i1 %7, %9
  %11 = xor i1 %5, %10
  %12 = xor i1 %11, true
  %13 = xor i1 true, true
  %14 = or i1 %12, %13
  %15 = xor i1 %14, true
  %16 = xor i1 false, true
  %17 = or i1 false, %16
  %18 = and i1 %15, %17
  %19 = xor i1 true, true
  %20 = and i1 %19, false
  %21 = xor i1 false, true
  %22 = and i1 true, %21
  %23 = or i1 %20, %22
  %24 = xor i1 true, true
  %25 = and i1 %24, false
  %26 = xor i1 false, true
  %27 = and i1 true, %26
  %28 = or i1 %25, %27
  %29 = xor i1 %23, %28
  %30 = xor i1 %tobool, true
  %31 = xor i1 %29, true
  %32 = or i1 %30, %31
  %33 = xor i1 %32, true
  %34 = xor i1 false, true
  %35 = or i1 false, %34
  %36 = and i1 %33, %35
  %37 = xor i1 %18, true
  %38 = xor i1 %36, true
  %39 = and i1 %37, %38
  %40 = xor i1 %39, true
  %41 = xor i1 false, true
  %42 = or i1 false, %41
  %43 = and i1 %40, %42
  br label %land.end

land.end:                                         ; preds = %land.rhs, %entry
  %44 = phi i1 [ false, %entry ], [ %43, %land.rhs ]
  %frombool = zext i1 %44 to i8
  store i8 %frombool, i8* %result, align 1
  %45 = load i8, i8* %result, align 1
  %tobool5 = trunc i8 %45 to i1
  br i1 %tobool5, label %if.then, label %if.else

if.then:                                          ; preds = %land.end
  %call6 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([18 x i8], [18 x i8]* @.str.2, i64 0, i64 0))
  br label %if.end

if.else:                                          ; preds = %land.end
  %call7 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([18 x i8], [18 x i8]* @.str.3, i64 0, i64 0))
  br label %if.end

if.end:                                           ; preds = %if.else, %if.then
  %46 = load i32, i32* %retval, align 4
  ret i32 %46
}

declare dso_local i32 @printf(i8*, ...) #3

declare dso_local i32 @scanf(i8*, ...) #3

; Function Attrs: argmemonly nofree nosync nounwind willreturn writeonly
declare void @llvm.memset.p0i8.i64(i8* nocapture writeonly, i8, i64, i1 immarg) #4

; Function Attrs: nounwind readonly willreturn
declare dso_local i32 @memcmp(i8*, i8*, i64) #1

attributes #0 = { noinline nounwind optnone uwtable mustprogress "disable-tail-calls"="false" "frame-pointer"="all" "less-precise-fpmad"="false" "min-legal-vector-width"="0" "no-infs-fp-math"="false" "no-jump-tables"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #1 = { nounwind readonly willreturn "disable-tail-calls"="false" "frame-pointer"="all" "less-precise-fpmad"="false" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #2 = { noinline norecurse optnone uwtable mustprogress "disable-tail-calls"="false" "frame-pointer"="all" "less-precise-fpmad"="false" "min-legal-vector-width"="0" "no-infs-fp-math"="false" "no-jump-tables"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #3 = { "disable-tail-calls"="false" "frame-pointer"="all" "less-precise-fpmad"="false" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #4 = { argmemonly nofree nosync nounwind willreturn writeonly }
attributes #5 = { nounwind readonly willreturn }

!llvm.module.flags = !{!0}
!llvm.ident = !{!1}

!0 = !{i32 1, !"wchar_size", i32 4}
!1 = !{!"clang version 12.0.1"}
!2 = distinct !{!2, !3}
!3 = !{!"llvm.loop.mustprogress"}
