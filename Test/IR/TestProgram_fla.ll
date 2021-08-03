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
  store i32 515401517, i32* %swVar.ptr, align 4
  %swVar.ptr14 = alloca i32, align 4
  store i32 515401517, i32* %swVar.ptr14, align 4
  br label %loopEntry12

loopEntry12:                                      ; preds = %loopEnd13, %entry
  %swVar15 = load i32, i32* %swVar.ptr14, align 4
  switch i32 %swVar15, label %swDefault16 [
    i32 515401517, label %loopEntry
    i32 1603298141, label %swDefault
    i32 959745354, label %0
    i32 797174614, label %1
    i32 685336862, label %3
    i32 279511477, label %for.cond
    i32 1224567888, label %4
    i32 919833745, label %5
    i32 16010878, label %6
    i32 1972567418, label %for.body
    i32 1023246850, label %13
    i32 169534503, label %16
    i32 1808424380, label %19
    i32 1806540408, label %for.inc
    i32 1765057505, label %20
    i32 1002969293, label %21
    i32 617141877, label %22
    i32 1012827168, label %for.end
    i32 1647459764, label %loopEnd
  ]

swDefault16:                                      ; preds = %loopEntry12
  br label %loopEnd13

loopEntry:                                        ; preds = %loopEntry12
  %swVar = load i32, i32* %swVar.ptr, align 4
  switch i32 %swVar, label %swDefault [
    i32 515401517, label %0
    i32 1603298141, label %1
    i32 959745354, label %3
    i32 797174614, label %for.cond
    i32 685336862, label %4
    i32 279511477, label %5
    i32 1224567888, label %6
    i32 919833745, label %for.body
    i32 16010878, label %13
    i32 1972567418, label %16
    i32 1023246850, label %19
    i32 169534503, label %for.inc
    i32 1808424380, label %20
    i32 1806540408, label %21
    i32 1765057505, label %22
    i32 1002969293, label %for.end
  ]

swDefault:                                        ; preds = %loopEntry12, %loopEntry
  store i32 1647459764, i32* %swVar.ptr14, align 4
  br label %loopEnd13

0:                                                ; preds = %loopEntry12, %loopEntry
  %i = alloca i32, align 4
  store i32* %i, i32** %i.reg2mem, align 8
  store i8* %dest, i8** %dest.addr, align 8
  store i8* %src, i8** %src.addr, align 8
  store i32 1603298141, i32* %swVar.ptr, align 4
  store i32 1647459764, i32* %swVar.ptr14, align 4
  br label %loopEnd13

1:                                                ; preds = %loopEntry12, %loopEntry
  %2 = load i8*, i8** %src.addr, align 8
  %call = call i64 @strlen(i8* %2) #5
  %conv = trunc i64 %call to i32
  store i32 %conv, i32* %conv.reg2mem, align 4
  store i32 959745354, i32* %swVar.ptr, align 4
  store i32 1647459764, i32* %swVar.ptr14, align 4
  br label %loopEnd13

3:                                                ; preds = %loopEntry12, %loopEntry
  %conv.reload = load volatile i32, i32* %conv.reg2mem, align 4
  store i32 %conv.reload, i32* %len, align 4
  %i.reload7 = load volatile i32*, i32** %i.reg2mem, align 8
  store i32 0, i32* %i.reload7, align 4
  store i32 797174614, i32* %swVar.ptr, align 4
  store i32 1647459764, i32* %swVar.ptr14, align 4
  br label %loopEnd13

for.cond:                                         ; preds = %loopEntry12, %loopEntry
  store i32 685336862, i32* %swVar.ptr, align 4
  store i32 1647459764, i32* %swVar.ptr14, align 4
  br label %loopEnd13

4:                                                ; preds = %loopEntry12, %loopEntry
  store i32 279511477, i32* %swVar.ptr, align 4
  store i32 1647459764, i32* %swVar.ptr14, align 4
  br label %loopEnd13

5:                                                ; preds = %loopEntry12, %loopEntry
  store i32 1224567888, i32* %swVar.ptr, align 4
  store i32 1647459764, i32* %swVar.ptr14, align 4
  br label %loopEnd13

6:                                                ; preds = %loopEntry12, %loopEntry
  %i.reload6 = load volatile i32*, i32** %i.reg2mem, align 8
  %7 = load i32, i32* %i.reload6, align 4
  %8 = load i32, i32* %len, align 4
  %cmp = icmp slt i32 %7, %8
  %9 = select i1 %cmp, i32 919833745, i32 1002969293
  store i32 %9, i32* %swVar.ptr, align 4
  store i32 1647459764, i32* %swVar.ptr14, align 4
  br label %loopEnd13

for.body:                                         ; preds = %loopEntry12, %loopEntry
  %10 = load i8*, i8** %src.addr, align 8
  %i.reload5 = load volatile i32*, i32** %i.reg2mem, align 8
  %11 = load i32, i32* %i.reload5, align 4
  %idxprom = sext i32 %11 to i64
  %arrayidx = getelementptr inbounds i8, i8* %10, i64 %idxprom
  %12 = load i8, i8* %arrayidx, align 1
  store i8 %12, i8* %.reg2mem, align 1
  store i32 16010878, i32* %swVar.ptr, align 4
  store i32 1647459764, i32* %swVar.ptr14, align 4
  br label %loopEnd13

13:                                               ; preds = %loopEntry12, %loopEntry
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
  store i32 1972567418, i32* %swVar.ptr, align 4
  store i32 1647459764, i32* %swVar.ptr14, align 4
  br label %loopEnd13

16:                                               ; preds = %loopEntry12, %loopEntry
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
  store i32 1023246850, i32* %swVar.ptr, align 4
  store i32 1647459764, i32* %swVar.ptr14, align 4
  br label %loopEnd13

19:                                               ; preds = %loopEntry12, %loopEntry
  %.reload11 = load volatile i8*, i8** %.reg2mem10, align 8
  %idxprom3.reload = load volatile i64, i64* %idxprom3.reg2mem, align 8
  %arrayidx4 = getelementptr inbounds i8, i8* %.reload11, i64 %idxprom3.reload
  %conv2.reload = load volatile i8, i8* %conv2.reg2mem, align 1
  store i8 %conv2.reload, i8* %arrayidx4, align 1
  store i32 169534503, i32* %swVar.ptr, align 4
  store i32 1647459764, i32* %swVar.ptr14, align 4
  br label %loopEnd13

for.inc:                                          ; preds = %loopEntry12, %loopEntry
  store i32 1808424380, i32* %swVar.ptr, align 4
  store i32 1647459764, i32* %swVar.ptr14, align 4
  br label %loopEnd13

20:                                               ; preds = %loopEntry12, %loopEntry
  store i32 1806540408, i32* %swVar.ptr, align 4
  store i32 1647459764, i32* %swVar.ptr14, align 4
  br label %loopEnd13

21:                                               ; preds = %loopEntry12, %loopEntry
  store i32 1765057505, i32* %swVar.ptr, align 4
  store i32 1647459764, i32* %swVar.ptr14, align 4
  br label %loopEnd13

22:                                               ; preds = %loopEntry12, %loopEntry
  %i.reload1 = load volatile i32*, i32** %i.reg2mem, align 8
  %23 = load i32, i32* %i.reload1, align 4
  %inc = add nsw i32 %23, 1
  %i.reload = load volatile i32*, i32** %i.reg2mem, align 8
  store i32 %inc, i32* %i.reload, align 4
  store i32 797174614, i32* %swVar.ptr, align 4
  store i32 1647459764, i32* %swVar.ptr14, align 4
  br label %loopEnd13

for.end:                                          ; preds = %loopEntry12, %loopEntry
  ret void

loopEnd:                                          ; preds = %loopEntry12
  store i32 515401517, i32* %swVar.ptr14, align 4
  br label %loopEnd13

loopEnd13:                                        ; preds = %loopEnd, %22, %21, %20, %for.inc, %19, %16, %13, %for.body, %6, %5, %4, %for.cond, %3, %1, %0, %swDefault, %swDefault16
  br label %loopEntry12
}

; Function Attrs: nounwind readonly willreturn
declare dso_local i64 @strlen(i8*) #1

; Function Attrs: noinline norecurse optnone uwtable mustprogress
define dso_local i32 @main() #2 {
entry:
  %arraydecay.reg2mem = alloca i8*, align 8
  %retval = alloca i32, align 4
  %dest = alloca [100 x i8], align 16
  %result = alloca i8, align 1
  %swVar.ptr = alloca i32, align 4
  store i32 515401517, i32* %swVar.ptr, align 4
  %.reg2mem = alloca i1, align 1
  %swVar.ptr3 = alloca i32, align 4
  store i32 515401517, i32* %swVar.ptr3, align 4
  br label %loopEntry1

loopEntry1:                                       ; preds = %loopEnd2, %entry
  %swVar4 = load i32, i32* %swVar.ptr3, align 4
  switch i32 %swVar4, label %swDefault5 [
    i32 515401517, label %loopEntry
    i32 1603298141, label %swDefault
    i32 959745354, label %0
    i32 797174614, label %1
    i32 685336862, label %3
    i32 279511477, label %land.rhs
    i32 1224567888, label %5
    i32 919833745, label %6
    i32 16010878, label %7
    i32 1972567418, label %land.end
    i32 1023246850, label %if.then
    i32 169534503, label %if.else
    i32 1808424380, label %if.end
    i32 1806540408, label %loopEnd
  ]

swDefault5:                                       ; preds = %loopEntry1
  br label %loopEnd2

loopEntry:                                        ; preds = %loopEntry1
  %swVar = load i32, i32* %swVar.ptr, align 4
  switch i32 %swVar, label %swDefault [
    i32 515401517, label %0
    i32 1603298141, label %1
    i32 959745354, label %3
    i32 797174614, label %land.rhs
    i32 685336862, label %5
    i32 279511477, label %6
    i32 1224567888, label %7
    i32 919833745, label %land.end
    i32 16010878, label %if.then
    i32 1972567418, label %if.else
    i32 1023246850, label %if.end
  ]

swDefault:                                        ; preds = %loopEntry1, %loopEntry
  store i32 1806540408, i32* %swVar.ptr3, align 4
  br label %loopEnd2

0:                                                ; preds = %loopEntry1, %loopEntry
  store i32 0, i32* %retval, align 4
  %call = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([25 x i8], [25 x i8]* @.str, i64 0, i64 0))
  %call1 = call i32 (i8*, ...) @scanf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @.str.1, i64 0, i64 0), i8* getelementptr inbounds ([100 x i8], [100 x i8]* @input, i64 0, i64 0))
  store i32 1603298141, i32* %swVar.ptr, align 4
  store i32 1806540408, i32* %swVar.ptr3, align 4
  br label %loopEnd2

1:                                                ; preds = %loopEntry1, %loopEntry
  %2 = bitcast [100 x i8]* %dest to i8*
  call void @llvm.memset.p0i8.i64(i8* align 16 %2, i8 0, i64 100, i1 false)
  %arraydecay = getelementptr inbounds [100 x i8], [100 x i8]* %dest, i64 0, i64 0
  store i8* %arraydecay, i8** %arraydecay.reg2mem, align 8
  store i32 959745354, i32* %swVar.ptr, align 4
  store i32 1806540408, i32* %swVar.ptr3, align 4
  br label %loopEnd2

3:                                                ; preds = %loopEntry1, %loopEntry
  %arraydecay.reload = load volatile i8*, i8** %arraydecay.reg2mem, align 8
  call void @_Z7encryptPhPc(i8* %arraydecay.reload, i8* getelementptr inbounds ([100 x i8], [100 x i8]* @input, i64 0, i64 0))
  %call2 = call i64 @strlen(i8* getelementptr inbounds ([100 x i8], [100 x i8]* @input, i64 0, i64 0)) #5
  %cmp = icmp eq i64 %call2, 22
  %4 = select i1 %cmp, i32 797174614, i32 919833745
  store i32 %4, i32* %swVar.ptr, align 4
  store i1 false, i1* %.reg2mem, align 1
  store i32 1806540408, i32* %swVar.ptr3, align 4
  br label %loopEnd2

land.rhs:                                         ; preds = %loopEntry1, %loopEntry
  store i32 685336862, i32* %swVar.ptr, align 4
  store i32 1806540408, i32* %swVar.ptr3, align 4
  br label %loopEnd2

5:                                                ; preds = %loopEntry1, %loopEntry
  store i32 279511477, i32* %swVar.ptr, align 4
  store i32 1806540408, i32* %swVar.ptr3, align 4
  br label %loopEnd2

6:                                                ; preds = %loopEntry1, %loopEntry
  store i32 1224567888, i32* %swVar.ptr, align 4
  store i32 1806540408, i32* %swVar.ptr3, align 4
  br label %loopEnd2

7:                                                ; preds = %loopEntry1, %loopEntry
  %arraydecay3 = getelementptr inbounds [100 x i8], [100 x i8]* %dest, i64 0, i64 0
  %call4 = call i32 @memcmp(i8* %arraydecay3, i8* getelementptr inbounds ([100 x i8], [100 x i8]* bitcast (<{ [22 x i8], [78 x i8] }>* @enc to [100 x i8]*), i64 0, i64 0), i64 22) #5
  %tobool = icmp ne i32 %call4, 0
  %lnot = xor i1 %tobool, true
  store i32 919833745, i32* %swVar.ptr, align 4
  store i1 %lnot, i1* %.reg2mem, align 1
  store i32 1806540408, i32* %swVar.ptr3, align 4
  br label %loopEnd2

land.end:                                         ; preds = %loopEntry1, %loopEntry
  %.reload = load i1, i1* %.reg2mem, align 1
  %frombool = zext i1 %.reload to i8
  store i8 %frombool, i8* %result, align 1
  %8 = load i8, i8* %result, align 1
  %tobool5 = trunc i8 %8 to i1
  %9 = select i1 %tobool5, i32 16010878, i32 1972567418
  store i32 %9, i32* %swVar.ptr, align 4
  store i32 1806540408, i32* %swVar.ptr3, align 4
  br label %loopEnd2

if.then:                                          ; preds = %loopEntry1, %loopEntry
  %call6 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([18 x i8], [18 x i8]* @.str.2, i64 0, i64 0))
  store i32 1023246850, i32* %swVar.ptr, align 4
  store i32 1806540408, i32* %swVar.ptr3, align 4
  br label %loopEnd2

if.else:                                          ; preds = %loopEntry1, %loopEntry
  %call7 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([18 x i8], [18 x i8]* @.str.3, i64 0, i64 0))
  store i32 1023246850, i32* %swVar.ptr, align 4
  store i32 1806540408, i32* %swVar.ptr3, align 4
  br label %loopEnd2

if.end:                                           ; preds = %loopEntry1, %loopEntry
  %10 = load i32, i32* %retval, align 4
  ret i32 %10

loopEnd:                                          ; preds = %loopEntry1
  store i32 515401517, i32* %swVar.ptr3, align 4
  br label %loopEnd2

loopEnd2:                                         ; preds = %loopEnd, %if.else, %if.then, %land.end, %7, %6, %5, %land.rhs, %3, %1, %0, %swDefault, %swDefault5
  br label %loopEntry1
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
