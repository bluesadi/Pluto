; ModuleID = 'IR/TestProgram_orig.ll'
source_filename = "TestProgram.cpp"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-unknown-linux-gnu"

@input = dso_local global i8* null, align 8
@enc = dso_local global <{ [22 x i8], [78 x i8] }> <{ [22 x i8] c"\86\8A}\87\93\8BM\81\80\8AC\7FII\86q\7FbSi(\9D", [78 x i8] zeroinitializer }>, align 16
@.str = private unnamed_addr constant [26 x i8] c"Welcome to LLVM world...\0A\00", align 1
@.str.1 = private unnamed_addr constant [33 x i8] c"Input your flag as an argument.\0A\00", align 1
@.str.2 = private unnamed_addr constant [18 x i8] c"Your flag is: %s\0A\00", align 1
@.str.3 = private unnamed_addr constant [18 x i8] c"Congratulations~\0A\00", align 1
@.str.4 = private unnamed_addr constant [18 x i8] c"Sorry try again.\0A\00", align 1

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
  %7 = sub i32 0, 23001684
  %8 = sub i32 %7, %6
  %9 = add i32 %8, 23001684
  %10 = sub i32 32, 1200885320
  %11 = add i32 %10, %9
  %12 = add i32 %11, 1200885320
  %13 = sub i32 0, %conv1
  %14 = add i32 0, %13
  %15 = sub i32 0, %12
  %16 = add i32 0, %15
  %17 = sub i32 0, %14
  %18 = sub i32 0, %16
  %19 = add i32 %17, %18
  %20 = sub i32 0, %19
  %21 = sub i32 0, 1420107690
  %22 = sub i32 %21, %20
  %23 = add i32 %22, 1420107690
  %24 = load i32, i32* %i, align 4
  %25 = xor i32 %23, -1
  %26 = and i32 %25, 355980019
  %27 = xor i32 355980019, -1
  %28 = and i32 %23, %27
  %29 = or i32 %26, %28
  %30 = xor i32 -1, -1
  %31 = and i32 %30, 355980019
  %32 = xor i32 355980019, -1
  %33 = and i32 -1, %32
  %34 = or i32 %31, %33
  %35 = xor i32 %29, %34
  %36 = xor i32 %24, -1
  %37 = xor i32 %35, %36
  %38 = and i32 %37, %35
  %39 = xor i32 %24, -1
  %40 = and i32 %39, 1162258439
  %41 = xor i32 1162258439, -1
  %42 = and i32 %24, %41
  %43 = or i32 %40, %42
  %44 = xor i32 -1, -1
  %45 = and i32 %44, 1162258439
  %46 = xor i32 1162258439, -1
  %47 = and i32 -1, %46
  %48 = or i32 %45, %47
  %49 = xor i32 %43, %48
  %50 = xor i32 %49, -1
  %51 = xor i32 %23, %50
  %52 = and i32 %51, %23
  %53 = xor i32 %38, -1
  %54 = xor i32 %52, -1
  %55 = and i32 %53, %54
  %56 = xor i32 %55, -1
  %57 = xor i32 1288347005, -1
  %58 = or i32 1288347005, %57
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
  %63 = add i32 %62, 436136534
  %64 = add i32 %63, 1480771545
  %65 = sub i32 %64, 436136534
  %66 = sub i32 0, %65
  %67 = sub i32 0, 1
  %68 = add i32 %66, %67
  %69 = sub i32 0, %68
  %70 = sub i32 0, 1480771545
  %71 = add i32 %69, %70
  store i32 %71, i32* %i, align 4
  br label %for.cond, !llvm.loop !2

for.end:                                          ; preds = %for.cond
  ret void
}

; Function Attrs: nounwind readonly willreturn
declare dso_local i64 @strlen(i8*) #1

; Function Attrs: noinline norecurse optnone uwtable mustprogress
define dso_local i32 @main(i32 %argc, i8** %argv) #2 {
entry:
  %retval = alloca i32, align 4
  %argc.addr = alloca i32, align 4
  %argv.addr = alloca i8**, align 8
  %dest = alloca [100 x i8], align 16
  %result = alloca i8, align 1
  store i32 0, i32* %retval, align 4
  store i32 %argc, i32* %argc.addr, align 4
  store i8** %argv, i8*** %argv.addr, align 8
  %call = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([26 x i8], [26 x i8]* @.str, i64 0, i64 0))
  %0 = load i32, i32* %argc.addr, align 4
  %cmp = icmp sle i32 %0, 1
  br i1 %cmp, label %if.then, label %if.end

if.then:                                          ; preds = %entry
  %call1 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([33 x i8], [33 x i8]* @.str.1, i64 0, i64 0))
  store i32 0, i32* %retval, align 4
  br label %if.end11

if.end:                                           ; preds = %entry
  %1 = load i8**, i8*** %argv.addr, align 8
  %arrayidx = getelementptr inbounds i8*, i8** %1, i64 1
  %2 = load i8*, i8** %arrayidx, align 8
  store i8* %2, i8** @input, align 8
  %3 = load i8*, i8** @input, align 8
  %call2 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([18 x i8], [18 x i8]* @.str.2, i64 0, i64 0), i8* %3)
  %4 = bitcast [100 x i8]* %dest to i8*
  call void @llvm.memset.p0i8.i64(i8* align 16 %4, i8 0, i64 100, i1 false)
  %arraydecay = getelementptr inbounds [100 x i8], [100 x i8]* %dest, i64 0, i64 0
  %5 = load i8*, i8** @input, align 8
  call void @_Z7encryptPhPc(i8* %arraydecay, i8* %5)
  %6 = load i8*, i8** @input, align 8
  %call3 = call i64 @strlen(i8* %6) #5
  %cmp4 = icmp eq i64 %call3, 22
  br i1 %cmp4, label %land.rhs, label %land.end

land.rhs:                                         ; preds = %if.end
  %arraydecay5 = getelementptr inbounds [100 x i8], [100 x i8]* %dest, i64 0, i64 0
  %call6 = call i32 @memcmp(i8* %arraydecay5, i8* getelementptr inbounds ([100 x i8], [100 x i8]* bitcast (<{ [22 x i8], [78 x i8] }>* @enc to [100 x i8]*), i64 0, i64 0), i64 22) #5
  %tobool = icmp ne i32 %call6, 0
  %7 = xor i1 %tobool, true
  %8 = and i1 %7, true
  %9 = xor i1 true, true
  %10 = and i1 %tobool, %9
  %11 = or i1 %8, %10
  %12 = xor i1 true, true
  %13 = xor i1 %11, %12
  %14 = and i1 %13, %11
  %15 = xor i1 true, true
  %16 = and i1 %15, true
  %17 = xor i1 true, true
  %18 = and i1 true, %17
  %19 = or i1 %16, %18
  %20 = xor i1 %tobool, true
  %21 = xor i1 %19, true
  %22 = or i1 %20, %21
  %23 = xor i1 %22, true
  %24 = xor i1 true, true
  %25 = or i1 true, %24
  %26 = and i1 %23, %25
  %27 = and i1 %14, %26
  %28 = xor i1 %14, %26
  %29 = or i1 %27, %28
  br label %land.end

land.end:                                         ; preds = %land.rhs, %if.end
  %30 = phi i1 [ false, %if.end ], [ %29, %land.rhs ]
  %frombool = zext i1 %30 to i8
  store i8 %frombool, i8* %result, align 1
  %31 = load i8, i8* %result, align 1
  %tobool7 = trunc i8 %31 to i1
  br i1 %tobool7, label %if.then8, label %if.else

if.then8:                                         ; preds = %land.end
  %call9 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([18 x i8], [18 x i8]* @.str.3, i64 0, i64 0))
  br label %if.end11

if.else:                                          ; preds = %land.end
  %call10 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([18 x i8], [18 x i8]* @.str.4, i64 0, i64 0))
  br label %if.end11

if.end11:                                         ; preds = %if.else, %if.then8, %if.then
  %32 = load i32, i32* %retval, align 4
  ret i32 %32
}

declare dso_local i32 @printf(i8*, ...) #3

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
