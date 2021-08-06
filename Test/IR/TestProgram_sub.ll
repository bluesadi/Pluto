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
  %7 = add i32 32, 858706015
  %8 = sub i32 %7, 1363031702
  %9 = sub i32 %8, 858706015
  %10 = sub i32 %9, 1883902740
  %11 = sub i32 %10, %6
  %12 = add i32 %11, 1883902740
  %13 = add i32 %12, 191376775
  %14 = add i32 %13, 1363031702
  %15 = sub i32 %14, 191376775
  %16 = sub i32 0, %conv1
  %17 = sub i32 0, 1956828592
  %18 = add i32 %16, %17
  %19 = sub i32 0, %18
  %20 = add i32 %19, 681987440
  %21 = add i32 %20, %15
  %22 = sub i32 %21, 681987440
  %23 = sub i32 %22, 1088262950
  %24 = sub i32 %23, 1956828592
  %25 = add i32 %24, 1088262950
  %26 = load i32, i32* %i, align 4
  %27 = xor i32 %25, -1
  %28 = and i32 %27, -1
  %29 = xor i32 -1, -1
  %30 = and i32 %25, %29
  %31 = or i32 %28, %30
  %32 = xor i32 %26, -1
  %33 = xor i32 %31, %32
  %34 = and i32 %33, %31
  %35 = xor i32 %26, -1
  %36 = and i32 %35, 228575649
  %37 = xor i32 228575649, -1
  %38 = and i32 %26, %37
  %39 = or i32 %36, %38
  %40 = xor i32 -1, -1
  %41 = and i32 %40, 228575649
  %42 = xor i32 228575649, -1
  %43 = and i32 -1, %42
  %44 = or i32 %41, %43
  %45 = xor i32 %39, %44
  %46 = xor i32 %25, -1
  %47 = xor i32 %45, -1
  %48 = or i32 %46, %47
  %49 = xor i32 %48, -1
  %50 = xor i32 1053732873, -1
  %51 = or i32 1053732873, %50
  %52 = and i32 %49, %51
  %53 = and i32 %34, %52
  %54 = xor i32 %34, %52
  %55 = or i32 %53, %54
  %conv2 = trunc i32 %55 to i8
  %56 = load i8*, i8** %dest.addr, align 8
  %57 = load i32, i32* %i, align 4
  %idxprom3 = sext i32 %57 to i64
  %arrayidx4 = getelementptr inbounds i8, i8* %56, i64 %idxprom3
  store i8 %conv2, i8* %arrayidx4, align 1
  br label %for.inc

for.inc:                                          ; preds = %for.body
  %58 = load i32, i32* %i, align 4
  %59 = sub i32 0, 2042623183
  %60 = sub i32 %58, %59
  %61 = sub i32 0, %60
  %62 = sub i32 0, 1
  %63 = add i32 %61, %62
  %64 = sub i32 0, %63
  %65 = sub i32 0, 2042623183
  %66 = add i32 %64, %65
  store i32 %66, i32* %i, align 4
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
  %13 = and i1 %12, true
  %14 = xor i1 true, true
  %15 = and i1 true, %14
  %16 = or i1 %13, %15
  %17 = xor i1 %11, %16
  %18 = xor i1 true, true
  %19 = xor i1 %17, %18
  %20 = and i1 %19, %17
  %21 = xor i1 true, true
  %22 = and i1 %21, true
  %23 = xor i1 true, true
  %24 = and i1 true, %23
  %25 = or i1 %22, %24
  %26 = xor i1 true, true
  %27 = and i1 %26, true
  %28 = xor i1 true, true
  %29 = and i1 true, %28
  %30 = or i1 %27, %29
  %31 = xor i1 %25, %30
  %32 = xor i1 %31, true
  %33 = xor i1 %tobool, %32
  %34 = and i1 %33, %tobool
  %35 = xor i1 %20, true
  %36 = xor i1 %34, true
  %37 = and i1 %35, %36
  %38 = xor i1 %37, true
  %39 = xor i1 false, true
  %40 = or i1 false, %39
  %41 = and i1 %38, %40
  br label %land.end

land.end:                                         ; preds = %land.rhs, %if.end
  %42 = phi i1 [ false, %if.end ], [ %41, %land.rhs ]
  %frombool = zext i1 %42 to i8
  store i8 %frombool, i8* %result, align 1
  %43 = load i8, i8* %result, align 1
  %tobool7 = trunc i8 %43 to i1
  br i1 %tobool7, label %if.then8, label %if.else

if.then8:                                         ; preds = %land.end
  %call9 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([18 x i8], [18 x i8]* @.str.3, i64 0, i64 0))
  br label %if.end11

if.else:                                          ; preds = %land.end
  %call10 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([18 x i8], [18 x i8]* @.str.4, i64 0, i64 0))
  br label %if.end11

if.end11:                                         ; preds = %if.else, %if.then8, %if.then
  %44 = load i32, i32* %retval, align 4
  ret i32 %44
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
