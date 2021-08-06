; ModuleID = 'IR/TestProgram_lowerswitch.ll'
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
  %idxprom3.reg2mem = alloca i64, align 8
  %.reg2mem10 = alloca i8*, align 8
  %conv2.reg2mem = alloca i8, align 1
  %.reg2mem8 = alloca i32, align 4
  %add.reg2mem = alloca i32, align 4
  %.reg2mem = alloca i8, align 1
  %conv.reg2mem = alloca i32, align 4
  %i.reg2mem = alloca i32*, align 8
  %dest.addr = alloca i8*, align 8
  %src.addr = alloca i8*, align 8
  %len = alloca i32, align 4
  %swVar.ptr = alloca i32, align 4
  store i32 1806328805, i32* %swVar.ptr, align 4
  br label %dispatchBB

dispatchBB:                                       ; preds = %entry, %returnBB
  %swVar = load i32, i32* %swVar.ptr, align 4
  switch i32 %swVar, label %swDefault [
    i32 1806328805, label %0
    i32 1569108140, label %1
    i32 860598470, label %3
    i32 682298107, label %for.cond
    i32 1746952169, label %4
    i32 1379741683, label %5
    i32 598433912, label %6
    i32 1189011028, label %for.body
    i32 939754968, label %13
    i32 77757015, label %16
    i32 1485996819, label %19
    i32 1305256641, label %for.inc
    i32 23280724, label %20
    i32 1167998218, label %21
    i32 342522435, label %22
    i32 492717831, label %for.end
  ]

swDefault:                                        ; preds = %dispatchBB
  br label %returnBB

0:                                                ; preds = %dispatchBB
  %i = alloca i32, align 4
  store i32* %i, i32** %i.reg2mem, align 8
  store i8* %dest, i8** %dest.addr, align 8
  store i8* %src, i8** %src.addr, align 8
  store i32 1569108140, i32* %swVar.ptr, align 4
  br label %returnBB

1:                                                ; preds = %dispatchBB
  %2 = load i8*, i8** %src.addr, align 8
  %call = call i64 @strlen(i8* %2) #5
  %conv = trunc i64 %call to i32
  store i32 %conv, i32* %conv.reg2mem, align 4
  store i32 860598470, i32* %swVar.ptr, align 4
  br label %returnBB

3:                                                ; preds = %dispatchBB
  %conv.reload = load volatile i32, i32* %conv.reg2mem, align 4
  store i32 %conv.reload, i32* %len, align 4
  %i.reload7 = load volatile i32*, i32** %i.reg2mem, align 8
  store i32 0, i32* %i.reload7, align 4
  store i32 682298107, i32* %swVar.ptr, align 4
  br label %returnBB

for.cond:                                         ; preds = %dispatchBB
  store i32 1746952169, i32* %swVar.ptr, align 4
  br label %returnBB

4:                                                ; preds = %dispatchBB
  store i32 1379741683, i32* %swVar.ptr, align 4
  br label %returnBB

5:                                                ; preds = %dispatchBB
  store i32 598433912, i32* %swVar.ptr, align 4
  br label %returnBB

6:                                                ; preds = %dispatchBB
  %i.reload6 = load volatile i32*, i32** %i.reg2mem, align 8
  %7 = load i32, i32* %i.reload6, align 4
  %8 = load i32, i32* %len, align 4
  %cmp = icmp slt i32 %7, %8
  %9 = select i1 %cmp, i32 1189011028, i32 492717831
  store i32 %9, i32* %swVar.ptr, align 4
  br label %returnBB

for.body:                                         ; preds = %dispatchBB
  %10 = load i8*, i8** %src.addr, align 8
  %i.reload5 = load volatile i32*, i32** %i.reg2mem, align 8
  %11 = load i32, i32* %i.reload5, align 4
  %idxprom = sext i32 %11 to i64
  %arrayidx = getelementptr inbounds i8, i8* %10, i64 %idxprom
  %12 = load i8, i8* %arrayidx, align 1
  store i8 %12, i8* %.reg2mem, align 1
  store i32 939754968, i32* %swVar.ptr, align 4
  br label %returnBB

13:                                               ; preds = %dispatchBB
  %.reload = load volatile i8, i8* %.reg2mem, align 1
  %conv1 = sext i8 %.reload to i32
  %i.reload4 = load volatile i32*, i32** %i.reg2mem, align 8
  %14 = load i32, i32* %i.reload4, align 4
  %sub = sub nsw i32 32, %14
  %add = add nsw i32 %conv1, %sub
  store i32 %add, i32* %add.reg2mem, align 4
  %i.reload3 = load volatile i32*, i32** %i.reg2mem, align 8
  %15 = load i32, i32* %i.reload3, align 4
  store i32 %15, i32* %.reg2mem8, align 4
  store i32 77757015, i32* %swVar.ptr, align 4
  br label %returnBB

16:                                               ; preds = %dispatchBB
  %add.reload = load volatile i32, i32* %add.reg2mem, align 4
  %.reload9 = load volatile i32, i32* %.reg2mem8, align 4
  %xor = xor i32 %add.reload, %.reload9
  %conv2 = trunc i32 %xor to i8
  store i8 %conv2, i8* %conv2.reg2mem, align 1
  %17 = load i8*, i8** %dest.addr, align 8
  store i8* %17, i8** %.reg2mem10, align 8
  %i.reload2 = load volatile i32*, i32** %i.reg2mem, align 8
  %18 = load i32, i32* %i.reload2, align 4
  %idxprom3 = sext i32 %18 to i64
  store i64 %idxprom3, i64* %idxprom3.reg2mem, align 8
  store i32 1485996819, i32* %swVar.ptr, align 4
  br label %returnBB

19:                                               ; preds = %dispatchBB
  %.reload11 = load volatile i8*, i8** %.reg2mem10, align 8
  %idxprom3.reload = load volatile i64, i64* %idxprom3.reg2mem, align 8
  %arrayidx4 = getelementptr inbounds i8, i8* %.reload11, i64 %idxprom3.reload
  %conv2.reload = load volatile i8, i8* %conv2.reg2mem, align 1
  store i8 %conv2.reload, i8* %arrayidx4, align 1
  store i32 1305256641, i32* %swVar.ptr, align 4
  br label %returnBB

for.inc:                                          ; preds = %dispatchBB
  store i32 23280724, i32* %swVar.ptr, align 4
  br label %returnBB

20:                                               ; preds = %dispatchBB
  store i32 1167998218, i32* %swVar.ptr, align 4
  br label %returnBB

21:                                               ; preds = %dispatchBB
  store i32 342522435, i32* %swVar.ptr, align 4
  br label %returnBB

22:                                               ; preds = %dispatchBB
  %i.reload1 = load volatile i32*, i32** %i.reg2mem, align 8
  %23 = load i32, i32* %i.reload1, align 4
  %inc = add nsw i32 %23, 1
  %i.reload = load volatile i32*, i32** %i.reg2mem, align 8
  store i32 %inc, i32* %i.reload, align 4
  store i32 682298107, i32* %swVar.ptr, align 4
  br label %returnBB

for.end:                                          ; preds = %dispatchBB
  ret void

returnBB:                                         ; preds = %22, %21, %20, %for.inc, %19, %16, %13, %for.body, %6, %5, %4, %for.cond, %3, %1, %0, %swDefault
  br label %dispatchBB
}

; Function Attrs: nounwind readonly willreturn
declare dso_local i64 @strlen(i8*) #1

; Function Attrs: noinline norecurse optnone uwtable mustprogress
define dso_local i32 @main(i32 %argc, i8** %argv) #2 {
entry:
  %.reg2mem4 = alloca i8*, align 8
  %result.reg2mem = alloca i8*, align 8
  %dest.reg2mem = alloca [100 x i8]*, align 8
  %retval = alloca i32, align 4
  %argc.addr = alloca i32, align 4
  %argv.addr = alloca i8**, align 8
  %swVar.ptr = alloca i32, align 4
  store i32 1503784440, i32* %swVar.ptr, align 4
  %.reg2mem = alloca i1, align 1
  br label %dispatchBB

dispatchBB:                                       ; preds = %entry, %returnBB
  %swVar = load i32, i32* %swVar.ptr, align 4
  switch i32 %swVar, label %swDefault [
    i32 1503784440, label %0
    i32 1362286915, label %1
    i32 58275522, label %2
    i32 539160995, label %if.then
    i32 1003084327, label %5
    i32 94889511, label %6
    i32 2010043519, label %7
    i32 1721907751, label %if.end
    i32 1809910853, label %10
    i32 1449022528, label %13
    i32 2142584874, label %16
    i32 1489690614, label %land.rhs
    i32 1581007276, label %18
    i32 243179376, label %19
    i32 1148535771, label %20
    i32 1002631769, label %land.end
    i32 1103777846, label %if.then8
    i32 1830833878, label %if.else
    i32 602100290, label %if.end11
  ]

swDefault:                                        ; preds = %dispatchBB
  br label %returnBB

0:                                                ; preds = %dispatchBB
  %dest = alloca [100 x i8], align 16
  store [100 x i8]* %dest, [100 x i8]** %dest.reg2mem, align 8
  %result = alloca i8, align 1
  store i8* %result, i8** %result.reg2mem, align 8
  store i32 0, i32* %retval, align 4
  store i32 1362286915, i32* %swVar.ptr, align 4
  br label %returnBB

1:                                                ; preds = %dispatchBB
  store i32 %argc, i32* %argc.addr, align 4
  store i8** %argv, i8*** %argv.addr, align 8
  %call = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([26 x i8], [26 x i8]* @.str, i64 0, i64 0))
  store i32 58275522, i32* %swVar.ptr, align 4
  br label %returnBB

2:                                                ; preds = %dispatchBB
  %3 = load i32, i32* %argc.addr, align 4
  %cmp = icmp sle i32 %3, 1
  %4 = select i1 %cmp, i32 539160995, i32 1721907751
  store i32 %4, i32* %swVar.ptr, align 4
  br label %returnBB

if.then:                                          ; preds = %dispatchBB
  store i32 1003084327, i32* %swVar.ptr, align 4
  br label %returnBB

5:                                                ; preds = %dispatchBB
  store i32 94889511, i32* %swVar.ptr, align 4
  br label %returnBB

6:                                                ; preds = %dispatchBB
  store i32 2010043519, i32* %swVar.ptr, align 4
  br label %returnBB

7:                                                ; preds = %dispatchBB
  %call1 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([33 x i8], [33 x i8]* @.str.1, i64 0, i64 0))
  store i32 0, i32* %retval, align 4
  store i32 602100290, i32* %swVar.ptr, align 4
  br label %returnBB

if.end:                                           ; preds = %dispatchBB
  %8 = load i8**, i8*** %argv.addr, align 8
  %arrayidx = getelementptr inbounds i8*, i8** %8, i64 1
  %9 = load i8*, i8** %arrayidx, align 8
  store i8* %9, i8** @input, align 8
  store i32 1809910853, i32* %swVar.ptr, align 4
  br label %returnBB

10:                                               ; preds = %dispatchBB
  %11 = load i8*, i8** @input, align 8
  %call2 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([18 x i8], [18 x i8]* @.str.2, i64 0, i64 0), i8* %11)
  %dest.reload2 = load volatile [100 x i8]*, [100 x i8]** %dest.reg2mem, align 8
  %12 = bitcast [100 x i8]* %dest.reload2 to i8*
  call void @llvm.memset.p0i8.i64(i8* align 16 %12, i8 0, i64 100, i1 false)
  store i32 1449022528, i32* %swVar.ptr, align 4
  br label %returnBB

13:                                               ; preds = %dispatchBB
  %dest.reload1 = load volatile [100 x i8]*, [100 x i8]** %dest.reg2mem, align 8
  %arraydecay = getelementptr inbounds [100 x i8], [100 x i8]* %dest.reload1, i64 0, i64 0
  %14 = load i8*, i8** @input, align 8
  call void @_Z7encryptPhPc(i8* %arraydecay, i8* %14)
  %15 = load i8*, i8** @input, align 8
  store i8* %15, i8** %.reg2mem4, align 8
  store i32 2142584874, i32* %swVar.ptr, align 4
  br label %returnBB

16:                                               ; preds = %dispatchBB
  %.reload5 = load volatile i8*, i8** %.reg2mem4, align 8
  %call3 = call i64 @strlen(i8* %.reload5) #5
  %cmp4 = icmp eq i64 %call3, 22
  %17 = select i1 %cmp4, i32 1489690614, i32 1002631769
  store i32 %17, i32* %swVar.ptr, align 4
  store i1 false, i1* %.reg2mem, align 1
  br label %returnBB

land.rhs:                                         ; preds = %dispatchBB
  store i32 1581007276, i32* %swVar.ptr, align 4
  br label %returnBB

18:                                               ; preds = %dispatchBB
  store i32 243179376, i32* %swVar.ptr, align 4
  br label %returnBB

19:                                               ; preds = %dispatchBB
  store i32 1148535771, i32* %swVar.ptr, align 4
  br label %returnBB

20:                                               ; preds = %dispatchBB
  %dest.reload = load volatile [100 x i8]*, [100 x i8]** %dest.reg2mem, align 8
  %arraydecay5 = getelementptr inbounds [100 x i8], [100 x i8]* %dest.reload, i64 0, i64 0
  %call6 = call i32 @memcmp(i8* %arraydecay5, i8* getelementptr inbounds ([100 x i8], [100 x i8]* bitcast (<{ [22 x i8], [78 x i8] }>* @enc to [100 x i8]*), i64 0, i64 0), i64 22) #5
  %tobool = icmp ne i32 %call6, 0
  %lnot = xor i1 %tobool, true
  store i32 1002631769, i32* %swVar.ptr, align 4
  store i1 %lnot, i1* %.reg2mem, align 1
  br label %returnBB

land.end:                                         ; preds = %dispatchBB
  %.reload = load i1, i1* %.reg2mem, align 1
  %frombool = zext i1 %.reload to i8
  %result.reload3 = load volatile i8*, i8** %result.reg2mem, align 8
  store i8 %frombool, i8* %result.reload3, align 1
  %result.reload = load volatile i8*, i8** %result.reg2mem, align 8
  %21 = load i8, i8* %result.reload, align 1
  %tobool7 = trunc i8 %21 to i1
  %22 = select i1 %tobool7, i32 1103777846, i32 1830833878
  store i32 %22, i32* %swVar.ptr, align 4
  br label %returnBB

if.then8:                                         ; preds = %dispatchBB
  %call9 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([18 x i8], [18 x i8]* @.str.3, i64 0, i64 0))
  store i32 602100290, i32* %swVar.ptr, align 4
  br label %returnBB

if.else:                                          ; preds = %dispatchBB
  %call10 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([18 x i8], [18 x i8]* @.str.4, i64 0, i64 0))
  store i32 602100290, i32* %swVar.ptr, align 4
  br label %returnBB

if.end11:                                         ; preds = %dispatchBB
  %23 = load i32, i32* %retval, align 4
  ret i32 %23

returnBB:                                         ; preds = %if.else, %if.then8, %land.end, %20, %19, %18, %land.rhs, %16, %13, %10, %if.end, %7, %6, %5, %if.then, %2, %1, %0, %swDefault
  br label %dispatchBB
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
