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
  %inc.reg2mem = alloca i32, align 4
  %.reg2mem32 = alloca i32, align 4
  %arrayidx4.reg2mem = alloca i8*, align 8
  %conv2.reg2mem = alloca i8, align 1
  %sub.reg2mem = alloca i32, align 4
  %conv1.reg2mem = alloca i32, align 4
  %cmp.reg2mem = alloca i1, align 1
  %.reg2mem20 = alloca i32, align 4
  %.reg2mem = alloca i32, align 4
  %i.reg2mem = alloca i32*, align 8
  %len.reg2mem = alloca i32*, align 8
  %src.addr.reg2mem = alloca i8**, align 8
  %dest.addr.reg2mem = alloca i8**, align 8
  %0 = call { i32, i32 } @llvm.x86.rdrand.32()
  %1 = extractvalue { i32, i32 } %0, 0
  %2 = add i32 %1, 1
  %3 = mul i32 %1, %2
  %4 = mul i32 %1, %1
  %5 = sub i32 %3, %4
  %6 = and i32 %5, 1
  %7 = icmp eq i32 %6, 1
  br i1 %7, label %bodyBB, label %bodyBBbodyBBcloneBB

bodyBB:                                           ; preds = %bodyBBbodyBBcloneBB, %entry
  %dest.addr = alloca i8*, align 8
  store i8** %dest.addr, i8*** %dest.addr.reg2mem, align 8
  %src.addr = alloca i8*, align 8
  store i8** %src.addr, i8*** %src.addr.reg2mem, align 8
  %len = alloca i32, align 4
  store i32* %len, i32** %len.reg2mem, align 8
  %i = alloca i32, align 4
  store i32* %i, i32** %i.reg2mem, align 8
  %dest.addr.reload1 = load volatile i8**, i8*** %dest.addr.reg2mem, align 8
  store i8* %dest, i8** %dest.addr.reload1, align 8
  %8 = add i32 %1, 1
  %9 = mul i32 %1, %8
  %10 = mul i32 %1, %1
  %11 = sub i32 %9, %10
  %12 = and i32 %11, 1
  %13 = icmp eq i32 %12, 1
  br i1 %13, label %endBB, label %bodyBBbodyBBcloneBB

endBB:                                            ; preds = %bodyBBbodyBBcloneBB, %bodyBB
  br label %14

14:                                               ; preds = %endBB
  %15 = call { i32, i32 } @llvm.x86.rdrand.32()
  %16 = extractvalue { i32, i32 } %15, 0
  %17 = sub i32 %16, 1
  %18 = add i32 %16, 3
  %19 = add i32 %16, 4
  %20 = sub i32 %16, 3
  %21 = mul i32 %17, %18
  %22 = mul i32 %19, %20
  %23 = sub i32 %21, %22
  %24 = sub i32 %23, 9
  %25 = and i32 %24, 1
  %26 = icmp eq i32 %25, 1
  br i1 %26, label %bodyBB12, label %bodyBB12bodyBB12cloneBB

bodyBB12:                                         ; preds = %bodyBB12bodyBB12cloneBB, %14
  %src.addr.reload3 = load volatile i8**, i8*** %src.addr.reg2mem, align 8
  store i8* %src, i8** %src.addr.reload3, align 8
  %src.addr.reload2 = load volatile i8**, i8*** %src.addr.reg2mem, align 8
  %27 = load i8*, i8** %src.addr.reload2, align 8
  %call = call i64 @strlen(i8* %27) #6
  %conv = trunc i64 %call to i32
  %len.reload4 = load volatile i32*, i32** %len.reg2mem, align 8
  store i32 %conv, i32* %len.reload4, align 4
  %28 = add i32 %16, 1
  %29 = mul i32 %16, %28
  %30 = mul i32 %16, %16
  %31 = sub i32 %29, %30
  %32 = and i32 %31, 1
  %33 = icmp eq i32 %32, 1
  br i1 %33, label %endBB13, label %bodyBB12bodyBB12cloneBB

endBB13:                                          ; preds = %bodyBB12bodyBB12cloneBB, %bodyBB12
  br label %34

34:                                               ; preds = %endBB13
  %35 = call { i32, i32 } @llvm.x86.rdrand.32()
  %36 = extractvalue { i32, i32 } %35, 0
  %37 = add i32 %36, 1
  %38 = mul i32 %36, %37
  %39 = mul i32 %36, %36
  %40 = sub i32 %38, %39
  %41 = and i32 %40, 1
  %42 = icmp eq i32 %41, 1
  br i1 %42, label %bodyBB14, label %bodyBB14bodyBB14cloneBB

bodyBB14:                                         ; preds = %bodyBB14bodyBB14cloneBB, %34
  %i.reload11 = load volatile i32*, i32** %i.reg2mem, align 8
  store i32 0, i32* %i.reload11, align 4
  %43 = sub i32 %36, 1
  %44 = add i32 %36, 3
  %45 = add i32 %36, 4
  %46 = sub i32 %36, 3
  %47 = mul i32 %43, %44
  %48 = mul i32 %45, %46
  %49 = sub i32 %47, %48
  %50 = sub i32 %49, 9
  %51 = and i32 %50, 1
  %52 = icmp eq i32 %51, 1
  br i1 %52, label %endBB15, label %bodyBB14bodyBB14cloneBB

endBB15:                                          ; preds = %bodyBB14bodyBB14cloneBB, %bodyBB14
  br label %for.cond

for.cond:                                         ; preds = %endBB37, %endBB15
  %53 = call { i32, i32 } @llvm.x86.rdrand.32()
  %54 = extractvalue { i32, i32 } %53, 0
  %55 = add i32 %54, 1
  %56 = mul i32 %54, %55
  %57 = mul i32 %54, %54
  %58 = sub i32 %56, %57
  %59 = and i32 %58, 1
  %60 = icmp eq i32 %59, 1
  br i1 %60, label %bodyBB16, label %bodyBB16bodyBB16cloneBB

bodyBB16:                                         ; preds = %bodyBB16bodyBB16cloneBB, %for.cond
  %i.reload10 = load volatile i32*, i32** %i.reg2mem, align 8
  %61 = load i32, i32* %i.reload10, align 4
  store i32 %61, i32* %.reg2mem, align 4
  %62 = add i32 %54, 1
  %63 = mul i32 %54, %62
  %64 = mul i32 %54, %54
  %65 = sub i32 %63, %64
  %66 = and i32 %65, 1
  %67 = icmp eq i32 %66, 1
  br i1 %67, label %endBB17, label %bodyBB16bodyBB16cloneBB

endBB17:                                          ; preds = %bodyBB16bodyBB16cloneBB, %bodyBB16
  br label %68

68:                                               ; preds = %endBB17
  %69 = call { i32, i32 } @llvm.x86.rdrand.32()
  %70 = extractvalue { i32, i32 } %69, 0
  %71 = sub i32 %70, 1
  %72 = add i32 %70, 3
  %73 = add i32 %70, 4
  %74 = sub i32 %70, 3
  %75 = mul i32 %71, %72
  %76 = mul i32 %73, %74
  %77 = sub i32 %75, %76
  %78 = sub i32 %77, 9
  %79 = and i32 %78, 1
  %80 = icmp eq i32 %79, 1
  br i1 %80, label %bodyBB18, label %bodyBB18bodyBB18cloneBB

bodyBB18:                                         ; preds = %bodyBB18bodyBB18cloneBB, %68
  %len.reload = load volatile i32*, i32** %len.reg2mem, align 8
  %81 = load i32, i32* %len.reload, align 4
  store i32 %81, i32* %.reg2mem20, align 4
  %82 = add i32 %70, 1
  %83 = mul i32 %70, %82
  %84 = mul i32 %70, %70
  %85 = sub i32 %83, %84
  %86 = and i32 %85, 1
  %87 = icmp eq i32 %86, 1
  br i1 %87, label %endBB19, label %bodyBB18bodyBB18cloneBB

endBB19:                                          ; preds = %bodyBB18bodyBB18cloneBB, %bodyBB18
  br label %88

88:                                               ; preds = %endBB19
  %89 = call { i32, i32 } @llvm.x86.rdrand.32()
  %90 = extractvalue { i32, i32 } %89, 0
  %91 = mul i32 %90, 3
  %92 = sub i32 %90, 2
  %93 = mul i32 %91, %92
  %94 = mul i32 %90, %90
  %95 = mul i32 %94, 3
  %96 = mul i32 %90, 7
  %97 = sub i32 %93, %95
  %98 = add i32 %96, %97
  %99 = and i32 %98, 1
  %100 = icmp eq i32 %99, 1
  br i1 %100, label %bodyBB22, label %bodyBB22bodyBB22cloneBB

bodyBB22:                                         ; preds = %bodyBB22bodyBB22cloneBB, %88
  %.reload = load volatile i32, i32* %.reg2mem, align 4
  %.reload21 = load volatile i32, i32* %.reg2mem20, align 4
  %cmp = icmp slt i32 %.reload, %.reload21
  store i1 %cmp, i1* %cmp.reg2mem, align 1
  %101 = mul i32 %90, 3
  %102 = sub i32 %90, 2
  %103 = mul i32 %101, %102
  %104 = mul i32 %90, %90
  %105 = mul i32 %104, 3
  %106 = mul i32 %90, 7
  %107 = sub i32 %103, %105
  %108 = add i32 %106, %107
  %109 = and i32 %108, 1
  %110 = icmp eq i32 %109, 1
  br i1 %110, label %endBB23, label %bodyBB22bodyBB22cloneBB

endBB23:                                          ; preds = %bodyBB22bodyBB22cloneBB, %bodyBB22
  %cmp.reload = load volatile i1, i1* %cmp.reg2mem, align 1
  br i1 %cmp.reload, label %for.body, label %for.end

for.body:                                         ; preds = %endBB23
  %111 = call { i32, i32 } @llvm.x86.rdrand.32()
  %112 = extractvalue { i32, i32 } %111, 0
  %113 = sub i32 %112, 1
  %114 = add i32 %112, 3
  %115 = add i32 %112, 4
  %116 = sub i32 %112, 3
  %117 = mul i32 %113, %114
  %118 = mul i32 %115, %116
  %119 = sub i32 %117, %118
  %120 = sub i32 %119, 9
  %121 = and i32 %120, 1
  %122 = icmp eq i32 %121, 1
  br i1 %122, label %bodyBB24, label %bodyBB24bodyBB24cloneBB

bodyBB24:                                         ; preds = %bodyBB24bodyBB24cloneBB, %for.body
  %src.addr.reload = load volatile i8**, i8*** %src.addr.reg2mem, align 8
  %123 = load i8*, i8** %src.addr.reload, align 8
  %i.reload9 = load volatile i32*, i32** %i.reg2mem, align 8
  %124 = load i32, i32* %i.reload9, align 4
  %idxprom = sext i32 %124 to i64
  %arrayidx = getelementptr inbounds i8, i8* %123, i64 %idxprom
  %125 = load i8, i8* %arrayidx, align 1
  %conv1 = sext i8 %125 to i32
  store i32 %conv1, i32* %conv1.reg2mem, align 4
  %i.reload8 = load volatile i32*, i32** %i.reg2mem, align 8
  %126 = load i32, i32* %i.reload8, align 4
  %sub = sub nsw i32 32, %126
  store i32 %sub, i32* %sub.reg2mem, align 4
  %127 = sub i32 %112, 1
  %128 = add i32 %112, 3
  %129 = add i32 %112, 4
  %130 = sub i32 %112, 3
  %131 = mul i32 %127, %128
  %132 = mul i32 %129, %130
  %133 = sub i32 %131, %132
  %134 = sub i32 %133, 9
  %135 = and i32 %134, 1
  %136 = icmp eq i32 %135, 1
  br i1 %136, label %endBB25, label %bodyBB24bodyBB24cloneBB

endBB25:                                          ; preds = %bodyBB24bodyBB24cloneBB, %bodyBB24
  br label %137

137:                                              ; preds = %endBB25
  %138 = call { i32, i32 } @llvm.x86.rdrand.32()
  %139 = extractvalue { i32, i32 } %138, 0
  %140 = sub i32 %139, 1
  %141 = add i32 %139, 3
  %142 = add i32 %139, 4
  %143 = sub i32 %139, 3
  %144 = mul i32 %140, %141
  %145 = mul i32 %142, %143
  %146 = sub i32 %144, %145
  %147 = sub i32 %146, 9
  %148 = and i32 %147, 1
  %149 = icmp eq i32 %148, 1
  br i1 %149, label %bodyBB26, label %bodyBB26bodyBB26cloneBB

bodyBB26:                                         ; preds = %bodyBB26bodyBB26cloneBB, %137
  %conv1.reload = load volatile i32, i32* %conv1.reg2mem, align 4
  %sub.reload = load volatile i32, i32* %sub.reg2mem, align 4
  %add = add nsw i32 %conv1.reload, %sub.reload
  %i.reload7 = load volatile i32*, i32** %i.reg2mem, align 8
  %150 = load i32, i32* %i.reload7, align 4
  %xor = xor i32 %add, %150
  %conv2 = trunc i32 %xor to i8
  store i8 %conv2, i8* %conv2.reg2mem, align 1
  %dest.addr.reload = load volatile i8**, i8*** %dest.addr.reg2mem, align 8
  %151 = load i8*, i8** %dest.addr.reload, align 8
  %i.reload6 = load volatile i32*, i32** %i.reg2mem, align 8
  %152 = load i32, i32* %i.reload6, align 4
  %idxprom3 = sext i32 %152 to i64
  %arrayidx4 = getelementptr inbounds i8, i8* %151, i64 %idxprom3
  store i8* %arrayidx4, i8** %arrayidx4.reg2mem, align 8
  %153 = add i32 %139, 1
  %154 = mul i32 %139, %153
  %155 = mul i32 %139, %139
  %156 = sub i32 %154, %155
  %157 = and i32 %156, 1
  %158 = icmp eq i32 %157, 1
  br i1 %158, label %endBB27, label %bodyBB26bodyBB26cloneBB

endBB27:                                          ; preds = %bodyBB26bodyBB26cloneBB, %bodyBB26
  br label %159

159:                                              ; preds = %endBB27
  %160 = call { i32, i32 } @llvm.x86.rdrand.32()
  %161 = extractvalue { i32, i32 } %160, 0
  %162 = sub i32 %161, 1
  %163 = add i32 %161, 3
  %164 = add i32 %161, 4
  %165 = sub i32 %161, 3
  %166 = mul i32 %162, %163
  %167 = mul i32 %164, %165
  %168 = sub i32 %166, %167
  %169 = sub i32 %168, 9
  %170 = and i32 %169, 1
  %171 = icmp eq i32 %170, 1
  br i1 %171, label %bodyBB28, label %bodyBB28bodyBB28cloneBB

bodyBB28:                                         ; preds = %bodyBB28bodyBB28cloneBB, %159
  %conv2.reload = load volatile i8, i8* %conv2.reg2mem, align 1
  %arrayidx4.reload = load volatile i8*, i8** %arrayidx4.reg2mem, align 8
  store i8 %conv2.reload, i8* %arrayidx4.reload, align 1
  %172 = add i32 %161, 1
  %173 = mul i32 %161, %172
  %174 = mul i32 %161, %161
  %175 = sub i32 %173, %174
  %176 = and i32 %175, 1
  %177 = icmp eq i32 %176, 1
  br i1 %177, label %endBB29, label %bodyBB28bodyBB28cloneBB

endBB29:                                          ; preds = %bodyBB28bodyBB28cloneBB, %bodyBB28
  br label %for.inc

for.inc:                                          ; preds = %endBB29
  %178 = call { i32, i32 } @llvm.x86.rdrand.32()
  %179 = extractvalue { i32, i32 } %178, 0
  %180 = sub i32 %179, 1
  %181 = add i32 %179, 3
  %182 = add i32 %179, 4
  %183 = sub i32 %179, 3
  %184 = mul i32 %180, %181
  %185 = mul i32 %182, %183
  %186 = sub i32 %184, %185
  %187 = sub i32 %186, 9
  %188 = and i32 %187, 1
  %189 = icmp eq i32 %188, 1
  br i1 %189, label %bodyBB30, label %bodyBB30bodyBB30cloneBB

bodyBB30:                                         ; preds = %bodyBB30bodyBB30cloneBB, %for.inc
  %i.reload5 = load volatile i32*, i32** %i.reg2mem, align 8
  %190 = load i32, i32* %i.reload5, align 4
  store i32 %190, i32* %.reg2mem32, align 4
  %191 = add i32 %179, 1
  %192 = mul i32 %179, %191
  %193 = mul i32 %179, %179
  %194 = sub i32 %192, %193
  %195 = and i32 %194, 1
  %196 = icmp eq i32 %195, 1
  br i1 %196, label %endBB31, label %bodyBB30bodyBB30cloneBB

endBB31:                                          ; preds = %bodyBB30bodyBB30cloneBB, %bodyBB30
  br label %197

197:                                              ; preds = %endBB31
  %198 = call { i32, i32 } @llvm.x86.rdrand.32()
  %199 = extractvalue { i32, i32 } %198, 0
  %200 = mul i32 %199, 3
  %201 = sub i32 %199, 2
  %202 = mul i32 %200, %201
  %203 = mul i32 %199, %199
  %204 = mul i32 %203, 3
  %205 = mul i32 %199, 7
  %206 = sub i32 %202, %204
  %207 = add i32 %205, %206
  %208 = and i32 %207, 1
  %209 = icmp eq i32 %208, 1
  br i1 %209, label %bodyBB34, label %bodyBB34bodyBB34cloneBB

bodyBB34:                                         ; preds = %bodyBB34bodyBB34cloneBB, %197
  %.reload33 = load volatile i32, i32* %.reg2mem32, align 4
  %inc = add nsw i32 %.reload33, 1
  store i32 %inc, i32* %inc.reg2mem, align 4
  %210 = add i32 %199, 1
  %211 = mul i32 %199, %210
  %212 = mul i32 %199, %199
  %213 = sub i32 %211, %212
  %214 = and i32 %213, 1
  %215 = icmp eq i32 %214, 1
  br i1 %215, label %endBB35, label %bodyBB34bodyBB34cloneBB

endBB35:                                          ; preds = %bodyBB34bodyBB34cloneBB, %bodyBB34
  br label %216

216:                                              ; preds = %endBB35
  %217 = call { i32, i32 } @llvm.x86.rdrand.32()
  %218 = extractvalue { i32, i32 } %217, 0
  %219 = mul i32 %218, 3
  %220 = sub i32 %218, 2
  %221 = mul i32 %219, %220
  %222 = mul i32 %218, %218
  %223 = mul i32 %222, 3
  %224 = mul i32 %218, 7
  %225 = sub i32 %221, %223
  %226 = add i32 %224, %225
  %227 = and i32 %226, 1
  %228 = icmp eq i32 %227, 1
  br i1 %228, label %bodyBB36, label %bodyBB36bodyBB36cloneBB

bodyBB36:                                         ; preds = %bodyBB36bodyBB36cloneBB, %216
  %i.reload = load volatile i32*, i32** %i.reg2mem, align 8
  %inc.reload = load volatile i32, i32* %inc.reg2mem, align 4
  store i32 %inc.reload, i32* %i.reload, align 4
  %229 = add i32 %218, 1
  %230 = mul i32 %218, %229
  %231 = mul i32 %218, %218
  %232 = sub i32 %230, %231
  %233 = and i32 %232, 1
  %234 = icmp eq i32 %233, 1
  br i1 %234, label %endBB37, label %bodyBB36bodyBB36cloneBB

endBB37:                                          ; preds = %bodyBB36bodyBB36cloneBB, %bodyBB36
  br label %for.cond, !llvm.loop !2

for.end:                                          ; preds = %endBB23
  %235 = call { i32, i32 } @llvm.x86.rdrand.32()
  %236 = extractvalue { i32, i32 } %235, 0
  %237 = add i32 %236, 1
  %238 = mul i32 %236, %237
  %239 = mul i32 %236, %236
  %240 = sub i32 %238, %239
  %241 = and i32 %240, 1
  %242 = icmp eq i32 %241, 1
  br i1 %242, label %bodyBB38, label %bodyBB38bodyBB38cloneBB

bodyBB38:                                         ; preds = %bodyBB38bodyBB38cloneBB, %for.end
  %243 = add i32 %236, 1
  %244 = mul i32 %236, %243
  %245 = mul i32 %236, %236
  %246 = sub i32 %244, %245
  %247 = and i32 %246, 1
  %248 = icmp eq i32 %247, 1
  br i1 %248, label %endBB39, label %bodyBB38bodyBB38cloneBB

endBB39:                                          ; preds = %bodyBB38bodyBB38cloneBB, %bodyBB38
  ret void

bodyBBbodyBBcloneBB:                              ; preds = %bodyBB, %entry
  %dest.addrbodyBBcloneBB = alloca i8*, align 8
  store i8** %dest.addrbodyBBcloneBB, i8*** %dest.addr.reg2mem, align 8
  %src.addrbodyBBcloneBB = alloca i8*, align 8
  store i8** %src.addrbodyBBcloneBB, i8*** %src.addr.reg2mem, align 8
  %lenbodyBBcloneBB = alloca i32, align 4
  store i32* %lenbodyBBcloneBB, i32** %len.reg2mem, align 8
  %ibodyBBcloneBB = alloca i32, align 4
  store i32* %ibodyBBcloneBB, i32** %i.reg2mem, align 8
  %dest.addr.reload1bodyBBcloneBB = load volatile i8**, i8*** %dest.addr.reg2mem, align 8
  store i8* %dest, i8** %dest.addr.reload1bodyBBcloneBB, align 8
  %249 = add i32 %1, 1
  %250 = mul i32 %1, %249
  %251 = mul i32 %1, %1
  %252 = sub i32 %250, %251
  %253 = and i32 %252, 1
  %254 = icmp eq i32 %253, 1
  br i1 %254, label %bodyBB, label %endBB

bodyBB12bodyBB12cloneBB:                          ; preds = %bodyBB12, %14
  %src.addr.reload3bodyBB12cloneBB = load volatile i8**, i8*** %src.addr.reg2mem, align 8
  store i8* %src, i8** %src.addr.reload3bodyBB12cloneBB, align 8
  %src.addr.reload2bodyBB12cloneBB = load volatile i8**, i8*** %src.addr.reg2mem, align 8
  %255 = load i8*, i8** %src.addr.reload2bodyBB12cloneBB, align 8
  %callbodyBB12cloneBB = call i64 @strlen(i8* %255) #6
  %convbodyBB12cloneBB = trunc i64 %callbodyBB12cloneBB to i32
  %len.reload4bodyBB12cloneBB = load volatile i32*, i32** %len.reg2mem, align 8
  store i32 %convbodyBB12cloneBB, i32* %len.reload4bodyBB12cloneBB, align 4
  %256 = sub i32 %16, 1
  %257 = add i32 %16, 3
  %258 = add i32 %16, 4
  %259 = sub i32 %16, 3
  %260 = mul i32 %256, %257
  %261 = mul i32 %258, %259
  %262 = sub i32 %260, %261
  %263 = sub i32 %262, 9
  %264 = and i32 %263, 1
  %265 = icmp eq i32 %264, 1
  br i1 %265, label %bodyBB12, label %endBB13

bodyBB14bodyBB14cloneBB:                          ; preds = %bodyBB14, %34
  %i.reload11bodyBB14cloneBB = load volatile i32*, i32** %i.reg2mem, align 8
  store i32 0, i32* %i.reload11bodyBB14cloneBB, align 4
  %266 = sub i32 %36, 1
  %267 = add i32 %36, 3
  %268 = add i32 %36, 4
  %269 = sub i32 %36, 3
  %270 = mul i32 %266, %267
  %271 = mul i32 %268, %269
  %272 = sub i32 %270, %271
  %273 = sub i32 %272, 9
  %274 = and i32 %273, 1
  %275 = icmp eq i32 %274, 1
  br i1 %275, label %bodyBB14, label %endBB15

bodyBB16bodyBB16cloneBB:                          ; preds = %bodyBB16, %for.cond
  %i.reload10bodyBB16cloneBB = load volatile i32*, i32** %i.reg2mem, align 8
  %276 = load i32, i32* %i.reload10bodyBB16cloneBB, align 4
  store i32 %276, i32* %.reg2mem, align 4
  %277 = sub i32 %54, 1
  %278 = add i32 %54, 3
  %279 = add i32 %54, 4
  %280 = sub i32 %54, 3
  %281 = mul i32 %277, %278
  %282 = mul i32 %279, %280
  %283 = sub i32 %281, %282
  %284 = sub i32 %283, 9
  %285 = and i32 %284, 1
  %286 = icmp eq i32 %285, 1
  br i1 %286, label %bodyBB16, label %endBB17

bodyBB18bodyBB18cloneBB:                          ; preds = %bodyBB18, %68
  %len.reloadbodyBB18cloneBB = load volatile i32*, i32** %len.reg2mem, align 8
  %287 = load i32, i32* %len.reloadbodyBB18cloneBB, align 4
  store i32 %287, i32* %.reg2mem20, align 4
  %288 = add i32 %70, 1
  %289 = mul i32 %70, %288
  %290 = mul i32 %70, %70
  %291 = sub i32 %289, %290
  %292 = and i32 %291, 1
  %293 = icmp eq i32 %292, 1
  br i1 %293, label %bodyBB18, label %endBB19

bodyBB22bodyBB22cloneBB:                          ; preds = %bodyBB22, %88
  %.reloadbodyBB22cloneBB = load volatile i32, i32* %.reg2mem, align 4
  %.reload21bodyBB22cloneBB = load volatile i32, i32* %.reg2mem20, align 4
  %cmpbodyBB22cloneBB = icmp slt i32 %.reloadbodyBB22cloneBB, %.reload21bodyBB22cloneBB
  store i1 %cmpbodyBB22cloneBB, i1* %cmp.reg2mem, align 1
  %294 = sub i32 %90, 1
  %295 = add i32 %90, 3
  %296 = add i32 %90, 4
  %297 = sub i32 %90, 3
  %298 = mul i32 %294, %295
  %299 = mul i32 %296, %297
  %300 = sub i32 %298, %299
  %301 = sub i32 %300, 9
  %302 = and i32 %301, 1
  %303 = icmp eq i32 %302, 1
  br i1 %303, label %bodyBB22, label %endBB23

bodyBB24bodyBB24cloneBB:                          ; preds = %bodyBB24, %for.body
  %src.addr.reloadbodyBB24cloneBB = load volatile i8**, i8*** %src.addr.reg2mem, align 8
  %304 = load i8*, i8** %src.addr.reloadbodyBB24cloneBB, align 8
  %i.reload9bodyBB24cloneBB = load volatile i32*, i32** %i.reg2mem, align 8
  %305 = load i32, i32* %i.reload9bodyBB24cloneBB, align 4
  %idxprombodyBB24cloneBB = sext i32 %305 to i64
  %arrayidxbodyBB24cloneBB = getelementptr inbounds i8, i8* %304, i64 %idxprombodyBB24cloneBB
  %306 = load i8, i8* %arrayidxbodyBB24cloneBB, align 1
  %conv1bodyBB24cloneBB = sext i8 %306 to i32
  store i32 %conv1bodyBB24cloneBB, i32* %conv1.reg2mem, align 4
  %i.reload8bodyBB24cloneBB = load volatile i32*, i32** %i.reg2mem, align 8
  %307 = load i32, i32* %i.reload8bodyBB24cloneBB, align 4
  %subbodyBB24cloneBB = sub nsw i32 32, %307
  store i32 %subbodyBB24cloneBB, i32* %sub.reg2mem, align 4
  %308 = mul i32 %112, 3
  %309 = sub i32 %112, 2
  %310 = mul i32 %308, %309
  %311 = mul i32 %112, %112
  %312 = mul i32 %311, 3
  %313 = mul i32 %112, 7
  %314 = sub i32 %310, %312
  %315 = add i32 %313, %314
  %316 = and i32 %315, 1
  %317 = icmp eq i32 %316, 1
  br i1 %317, label %bodyBB24, label %endBB25

bodyBB26bodyBB26cloneBB:                          ; preds = %bodyBB26, %137
  %conv1.reloadbodyBB26cloneBB = load volatile i32, i32* %conv1.reg2mem, align 4
  %sub.reloadbodyBB26cloneBB = load volatile i32, i32* %sub.reg2mem, align 4
  %addbodyBB26cloneBB = add nsw i32 %conv1.reloadbodyBB26cloneBB, %sub.reloadbodyBB26cloneBB
  %i.reload7bodyBB26cloneBB = load volatile i32*, i32** %i.reg2mem, align 8
  %318 = load i32, i32* %i.reload7bodyBB26cloneBB, align 4
  %xorbodyBB26cloneBB = xor i32 %addbodyBB26cloneBB, %318
  %conv2bodyBB26cloneBB = trunc i32 %xorbodyBB26cloneBB to i8
  store i8 %conv2bodyBB26cloneBB, i8* %conv2.reg2mem, align 1
  %dest.addr.reloadbodyBB26cloneBB = load volatile i8**, i8*** %dest.addr.reg2mem, align 8
  %319 = load i8*, i8** %dest.addr.reloadbodyBB26cloneBB, align 8
  %i.reload6bodyBB26cloneBB = load volatile i32*, i32** %i.reg2mem, align 8
  %320 = load i32, i32* %i.reload6bodyBB26cloneBB, align 4
  %idxprom3bodyBB26cloneBB = sext i32 %320 to i64
  %arrayidx4bodyBB26cloneBB = getelementptr inbounds i8, i8* %319, i64 %idxprom3bodyBB26cloneBB
  store i8* %arrayidx4bodyBB26cloneBB, i8** %arrayidx4.reg2mem, align 8
  %321 = sub i32 %139, 1
  %322 = add i32 %139, 3
  %323 = add i32 %139, 4
  %324 = sub i32 %139, 3
  %325 = mul i32 %321, %322
  %326 = mul i32 %323, %324
  %327 = sub i32 %325, %326
  %328 = sub i32 %327, 9
  %329 = and i32 %328, 1
  %330 = icmp eq i32 %329, 1
  br i1 %330, label %bodyBB26, label %endBB27

bodyBB28bodyBB28cloneBB:                          ; preds = %bodyBB28, %159
  %conv2.reloadbodyBB28cloneBB = load volatile i8, i8* %conv2.reg2mem, align 1
  %arrayidx4.reloadbodyBB28cloneBB = load volatile i8*, i8** %arrayidx4.reg2mem, align 8
  store i8 %conv2.reloadbodyBB28cloneBB, i8* %arrayidx4.reloadbodyBB28cloneBB, align 1
  %331 = mul i32 %161, 3
  %332 = sub i32 %161, 2
  %333 = mul i32 %331, %332
  %334 = mul i32 %161, %161
  %335 = mul i32 %334, 3
  %336 = mul i32 %161, 7
  %337 = sub i32 %333, %335
  %338 = add i32 %336, %337
  %339 = and i32 %338, 1
  %340 = icmp eq i32 %339, 1
  br i1 %340, label %bodyBB28, label %endBB29

bodyBB30bodyBB30cloneBB:                          ; preds = %bodyBB30, %for.inc
  %i.reload5bodyBB30cloneBB = load volatile i32*, i32** %i.reg2mem, align 8
  %341 = load i32, i32* %i.reload5bodyBB30cloneBB, align 4
  store i32 %341, i32* %.reg2mem32, align 4
  %342 = sub i32 %179, 1
  %343 = add i32 %179, 3
  %344 = add i32 %179, 4
  %345 = sub i32 %179, 3
  %346 = mul i32 %342, %343
  %347 = mul i32 %344, %345
  %348 = sub i32 %346, %347
  %349 = sub i32 %348, 9
  %350 = and i32 %349, 1
  %351 = icmp eq i32 %350, 1
  br i1 %351, label %bodyBB30, label %endBB31

bodyBB34bodyBB34cloneBB:                          ; preds = %bodyBB34, %197
  %.reload33bodyBB34cloneBB = load volatile i32, i32* %.reg2mem32, align 4
  %incbodyBB34cloneBB = add nsw i32 %.reload33bodyBB34cloneBB, 1
  store i32 %incbodyBB34cloneBB, i32* %inc.reg2mem, align 4
  %352 = add i32 %199, 1
  %353 = mul i32 %199, %352
  %354 = mul i32 %199, %199
  %355 = sub i32 %353, %354
  %356 = and i32 %355, 1
  %357 = icmp eq i32 %356, 1
  br i1 %357, label %bodyBB34, label %endBB35

bodyBB36bodyBB36cloneBB:                          ; preds = %bodyBB36, %216
  %i.reloadbodyBB36cloneBB = load volatile i32*, i32** %i.reg2mem, align 8
  %inc.reloadbodyBB36cloneBB = load volatile i32, i32* %inc.reg2mem, align 4
  store i32 %inc.reloadbodyBB36cloneBB, i32* %i.reloadbodyBB36cloneBB, align 4
  %358 = mul i32 %218, 3
  %359 = sub i32 %218, 2
  %360 = mul i32 %358, %359
  %361 = mul i32 %218, %218
  %362 = mul i32 %361, 3
  %363 = mul i32 %218, 7
  %364 = sub i32 %360, %362
  %365 = add i32 %363, %364
  %366 = and i32 %365, 1
  %367 = icmp eq i32 %366, 1
  br i1 %367, label %bodyBB36, label %endBB37

bodyBB38bodyBB38cloneBB:                          ; preds = %bodyBB38, %for.end
  %368 = mul i32 %236, 3
  %369 = sub i32 %236, 2
  %370 = mul i32 %368, %369
  %371 = mul i32 %236, %236
  %372 = mul i32 %371, 3
  %373 = mul i32 %236, 7
  %374 = sub i32 %370, %372
  %375 = add i32 %373, %374
  %376 = and i32 %375, 1
  %377 = icmp eq i32 %376, 1
  br i1 %377, label %bodyBB38, label %endBB39
}

; Function Attrs: nounwind readonly willreturn
declare dso_local i64 @strlen(i8*) #1

; Function Attrs: noinline norecurse optnone uwtable mustprogress
define dso_local i32 @main(i32 %argc, i8** %argv) #2 {
entry:
  %.reg2mem52 = alloca i32, align 4
  %tobool7.reg2mem = alloca i1, align 1
  %lnot.reg2mem = alloca i1, align 1
  %call6.reg2mem = alloca i32, align 4
  %arraydecay5.reg2mem = alloca i8*, align 8
  %cmp4.reg2mem = alloca i1, align 1
  %.reg2mem22 = alloca i8*, align 8
  %cmp.reg2mem = alloca i1, align 1
  %.reg2mem = alloca i32, align 4
  %result.reg2mem = alloca i8*, align 8
  %dest.reg2mem = alloca [100 x i8]*, align 8
  %argv.addr.reg2mem = alloca i8***, align 8
  %argc.addr.reg2mem = alloca i32*, align 8
  %retval.reg2mem = alloca i32*, align 8
  %0 = call { i32, i32 } @llvm.x86.rdrand.32()
  %1 = extractvalue { i32, i32 } %0, 0
  %2 = add i32 %1, 1
  %3 = mul i32 %1, %2
  %4 = mul i32 %1, %1
  %5 = sub i32 %3, %4
  %6 = and i32 %5, 1
  %7 = icmp eq i32 %6, 1
  br i1 %7, label %bodyBB, label %bodyBBbodyBBcloneBB

bodyBB:                                           ; preds = %bodyBBbodyBBcloneBB, %entry
  %retval = alloca i32, align 4
  store i32* %retval, i32** %retval.reg2mem, align 8
  %argc.addr = alloca i32, align 4
  store i32* %argc.addr, i32** %argc.addr.reg2mem, align 8
  %argv.addr = alloca i8**, align 8
  store i8*** %argv.addr, i8**** %argv.addr.reg2mem, align 8
  %dest = alloca [100 x i8], align 16
  store [100 x i8]* %dest, [100 x i8]** %dest.reg2mem, align 8
  %result = alloca i8, align 1
  store i8* %result, i8** %result.reg2mem, align 8
  %8 = mul i32 %1, 3
  %9 = sub i32 %1, 2
  %10 = mul i32 %8, %9
  %11 = mul i32 %1, %1
  %12 = mul i32 %11, 3
  %13 = mul i32 %1, 7
  %14 = sub i32 %10, %12
  %15 = add i32 %13, %14
  %16 = and i32 %15, 1
  %17 = icmp eq i32 %16, 1
  br i1 %17, label %endBB, label %bodyBBbodyBBcloneBB

endBB:                                            ; preds = %bodyBBbodyBBcloneBB, %bodyBB
  br label %18

18:                                               ; preds = %endBB
  %19 = call { i32, i32 } @llvm.x86.rdrand.32()
  %20 = extractvalue { i32, i32 } %19, 0
  %21 = add i32 %20, 1
  %22 = mul i32 %20, %21
  %23 = mul i32 %20, %20
  %24 = sub i32 %22, %23
  %25 = and i32 %24, 1
  %26 = icmp eq i32 %25, 1
  br i1 %26, label %bodyBB8, label %bodyBB8bodyBB8cloneBB

bodyBB8:                                          ; preds = %bodyBB8bodyBB8cloneBB, %18
  %retval.reload2 = load volatile i32*, i32** %retval.reg2mem, align 8
  store i32 0, i32* %retval.reload2, align 4
  %argc.addr.reload3 = load volatile i32*, i32** %argc.addr.reg2mem, align 8
  store i32 %argc, i32* %argc.addr.reload3, align 4
  %argv.addr.reload4 = load volatile i8***, i8**** %argv.addr.reg2mem, align 8
  store i8** %argv, i8*** %argv.addr.reload4, align 8
  %call = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([26 x i8], [26 x i8]* @.str, i64 0, i64 0))
  %argc.addr.reload = load volatile i32*, i32** %argc.addr.reg2mem, align 8
  %27 = load i32, i32* %argc.addr.reload, align 4
  store i32 %27, i32* %.reg2mem, align 4
  %28 = mul i32 %20, 3
  %29 = sub i32 %20, 2
  %30 = mul i32 %28, %29
  %31 = mul i32 %20, %20
  %32 = mul i32 %31, 3
  %33 = mul i32 %20, 7
  %34 = sub i32 %30, %32
  %35 = add i32 %33, %34
  %36 = and i32 %35, 1
  %37 = icmp eq i32 %36, 1
  br i1 %37, label %endBB9, label %bodyBB8bodyBB8cloneBB

endBB9:                                           ; preds = %bodyBB8bodyBB8cloneBB, %bodyBB8
  br label %38

38:                                               ; preds = %endBB9
  %39 = call { i32, i32 } @llvm.x86.rdrand.32()
  %40 = extractvalue { i32, i32 } %39, 0
  %41 = mul i32 %40, 3
  %42 = sub i32 %40, 2
  %43 = mul i32 %41, %42
  %44 = mul i32 %40, %40
  %45 = mul i32 %44, 3
  %46 = mul i32 %40, 7
  %47 = sub i32 %43, %45
  %48 = add i32 %46, %47
  %49 = and i32 %48, 1
  %50 = icmp eq i32 %49, 1
  br i1 %50, label %bodyBB10, label %bodyBB10bodyBB10cloneBB

bodyBB10:                                         ; preds = %bodyBB10bodyBB10cloneBB, %38
  %.reload = load volatile i32, i32* %.reg2mem, align 4
  %cmp = icmp sle i32 %.reload, 1
  store i1 %cmp, i1* %cmp.reg2mem, align 1
  %51 = add i32 %40, 1
  %52 = mul i32 %40, %51
  %53 = mul i32 %40, %40
  %54 = sub i32 %52, %53
  %55 = and i32 %54, 1
  %56 = icmp eq i32 %55, 1
  br i1 %56, label %endBB11, label %bodyBB10bodyBB10cloneBB

endBB11:                                          ; preds = %bodyBB10bodyBB10cloneBB, %bodyBB10
  %cmp.reload = load volatile i1, i1* %cmp.reg2mem, align 1
  br i1 %cmp.reload, label %if.then, label %if.end

if.then:                                          ; preds = %endBB11
  %57 = call { i32, i32 } @llvm.x86.rdrand.32()
  %58 = extractvalue { i32, i32 } %57, 0
  %59 = mul i32 %58, 3
  %60 = sub i32 %58, 2
  %61 = mul i32 %59, %60
  %62 = mul i32 %58, %58
  %63 = mul i32 %62, 3
  %64 = mul i32 %58, 7
  %65 = sub i32 %61, %63
  %66 = add i32 %64, %65
  %67 = and i32 %66, 1
  %68 = icmp eq i32 %67, 1
  br i1 %68, label %bodyBB12, label %bodyBB12bodyBB12cloneBB

bodyBB12:                                         ; preds = %bodyBB12bodyBB12cloneBB, %if.then
  %69 = sub i32 %58, 1
  %70 = add i32 %58, 3
  %71 = add i32 %58, 4
  %72 = sub i32 %58, 3
  %73 = mul i32 %69, %70
  %74 = mul i32 %71, %72
  %75 = sub i32 %73, %74
  %76 = sub i32 %75, 9
  %77 = and i32 %76, 1
  %78 = icmp eq i32 %77, 1
  br i1 %78, label %endBB13, label %bodyBB12bodyBB12cloneBB

endBB13:                                          ; preds = %bodyBB12bodyBB12cloneBB, %bodyBB12
  br label %79

79:                                               ; preds = %endBB13
  %80 = call { i32, i32 } @llvm.x86.rdrand.32()
  %81 = extractvalue { i32, i32 } %80, 0
  %82 = sub i32 %81, 1
  %83 = add i32 %81, 3
  %84 = add i32 %81, 4
  %85 = sub i32 %81, 3
  %86 = mul i32 %82, %83
  %87 = mul i32 %84, %85
  %88 = sub i32 %86, %87
  %89 = sub i32 %88, 9
  %90 = and i32 %89, 1
  %91 = icmp eq i32 %90, 1
  br i1 %91, label %bodyBB14, label %bodyBB14bodyBB14cloneBB

bodyBB14:                                         ; preds = %bodyBB14bodyBB14cloneBB, %79
  %92 = sub i32 %81, 1
  %93 = add i32 %81, 3
  %94 = add i32 %81, 4
  %95 = sub i32 %81, 3
  %96 = mul i32 %92, %93
  %97 = mul i32 %94, %95
  %98 = sub i32 %96, %97
  %99 = sub i32 %98, 9
  %100 = and i32 %99, 1
  %101 = icmp eq i32 %100, 1
  br i1 %101, label %endBB15, label %bodyBB14bodyBB14cloneBB

endBB15:                                          ; preds = %bodyBB14bodyBB14cloneBB, %bodyBB14
  br label %102

102:                                              ; preds = %endBB15
  %103 = call { i32, i32 } @llvm.x86.rdrand.32()
  %104 = extractvalue { i32, i32 } %103, 0
  %105 = sub i32 %104, 1
  %106 = add i32 %104, 3
  %107 = add i32 %104, 4
  %108 = sub i32 %104, 3
  %109 = mul i32 %105, %106
  %110 = mul i32 %107, %108
  %111 = sub i32 %109, %110
  %112 = sub i32 %111, 9
  %113 = and i32 %112, 1
  %114 = icmp eq i32 %113, 1
  br i1 %114, label %bodyBB16, label %bodyBB16bodyBB16cloneBB

bodyBB16:                                         ; preds = %bodyBB16bodyBB16cloneBB, %102
  %call1 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([33 x i8], [33 x i8]* @.str.1, i64 0, i64 0))
  %retval.reload1 = load volatile i32*, i32** %retval.reg2mem, align 8
  store i32 0, i32* %retval.reload1, align 4
  %115 = mul i32 %104, 3
  %116 = sub i32 %104, 2
  %117 = mul i32 %115, %116
  %118 = mul i32 %104, %104
  %119 = mul i32 %118, 3
  %120 = mul i32 %104, 7
  %121 = sub i32 %117, %119
  %122 = add i32 %120, %121
  %123 = and i32 %122, 1
  %124 = icmp eq i32 %123, 1
  br i1 %124, label %endBB17, label %bodyBB16bodyBB16cloneBB

endBB17:                                          ; preds = %bodyBB16bodyBB16cloneBB, %bodyBB16
  br label %if.end11

if.end:                                           ; preds = %endBB11
  %125 = call { i32, i32 } @llvm.x86.rdrand.32()
  %126 = extractvalue { i32, i32 } %125, 0
  %127 = add i32 %126, 1
  %128 = mul i32 %126, %127
  %129 = mul i32 %126, %126
  %130 = sub i32 %128, %129
  %131 = and i32 %130, 1
  %132 = icmp eq i32 %131, 1
  br i1 %132, label %bodyBB18, label %bodyBB18bodyBB18cloneBB

bodyBB18:                                         ; preds = %bodyBB18bodyBB18cloneBB, %if.end
  %argv.addr.reload = load volatile i8***, i8**** %argv.addr.reg2mem, align 8
  %133 = load i8**, i8*** %argv.addr.reload, align 8
  %arrayidx = getelementptr inbounds i8*, i8** %133, i64 1
  %134 = load i8*, i8** %arrayidx, align 8
  store i8* %134, i8** @input, align 8
  %135 = load i8*, i8** @input, align 8
  %call2 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([18 x i8], [18 x i8]* @.str.2, i64 0, i64 0), i8* %135)
  %136 = sub i32 %126, 1
  %137 = add i32 %126, 3
  %138 = add i32 %126, 4
  %139 = sub i32 %126, 3
  %140 = mul i32 %136, %137
  %141 = mul i32 %138, %139
  %142 = sub i32 %140, %141
  %143 = sub i32 %142, 9
  %144 = and i32 %143, 1
  %145 = icmp eq i32 %144, 1
  br i1 %145, label %endBB19, label %bodyBB18bodyBB18cloneBB

endBB19:                                          ; preds = %bodyBB18bodyBB18cloneBB, %bodyBB18
  br label %146

146:                                              ; preds = %endBB19
  %147 = call { i32, i32 } @llvm.x86.rdrand.32()
  %148 = extractvalue { i32, i32 } %147, 0
  %149 = add i32 %148, 1
  %150 = mul i32 %148, %149
  %151 = mul i32 %148, %148
  %152 = sub i32 %150, %151
  %153 = and i32 %152, 1
  %154 = icmp eq i32 %153, 1
  br i1 %154, label %bodyBB20, label %bodyBB20bodyBB20cloneBB

bodyBB20:                                         ; preds = %bodyBB20bodyBB20cloneBB, %146
  %dest.reload6 = load volatile [100 x i8]*, [100 x i8]** %dest.reg2mem, align 8
  %155 = bitcast [100 x i8]* %dest.reload6 to i8*
  call void @llvm.memset.p0i8.i64(i8* align 16 %155, i8 0, i64 100, i1 false)
  %dest.reload5 = load volatile [100 x i8]*, [100 x i8]** %dest.reg2mem, align 8
  %arraydecay = getelementptr inbounds [100 x i8], [100 x i8]* %dest.reload5, i64 0, i64 0
  %156 = load i8*, i8** @input, align 8
  call void @_Z7encryptPhPc(i8* %arraydecay, i8* %156)
  %157 = load i8*, i8** @input, align 8
  store i8* %157, i8** %.reg2mem22, align 8
  %158 = add i32 %148, 1
  %159 = mul i32 %148, %158
  %160 = mul i32 %148, %148
  %161 = sub i32 %159, %160
  %162 = and i32 %161, 1
  %163 = icmp eq i32 %162, 1
  br i1 %163, label %endBB21, label %bodyBB20bodyBB20cloneBB

endBB21:                                          ; preds = %bodyBB20bodyBB20cloneBB, %bodyBB20
  br label %164

164:                                              ; preds = %endBB21
  %165 = call { i32, i32 } @llvm.x86.rdrand.32()
  %166 = extractvalue { i32, i32 } %165, 0
  %167 = mul i32 %166, 3
  %168 = sub i32 %166, 2
  %169 = mul i32 %167, %168
  %170 = mul i32 %166, %166
  %171 = mul i32 %170, 3
  %172 = mul i32 %166, 7
  %173 = sub i32 %169, %171
  %174 = add i32 %172, %173
  %175 = and i32 %174, 1
  %176 = icmp eq i32 %175, 1
  br i1 %176, label %bodyBB24, label %bodyBB24bodyBB24cloneBB

bodyBB24:                                         ; preds = %bodyBB24bodyBB24cloneBB, %164
  %.reload23 = load volatile i8*, i8** %.reg2mem22, align 8
  %call3 = call i64 @strlen(i8* %.reload23) #6
  %cmp4 = icmp eq i64 %call3, 22
  store i1 %cmp4, i1* %cmp4.reg2mem, align 1
  %177 = mul i32 %166, 3
  %178 = sub i32 %166, 2
  %179 = mul i32 %177, %178
  %180 = mul i32 %166, %166
  %181 = mul i32 %180, 3
  %182 = mul i32 %166, 7
  %183 = sub i32 %179, %181
  %184 = add i32 %182, %183
  %185 = and i32 %184, 1
  %186 = icmp eq i32 %185, 1
  br i1 %186, label %endBB25, label %bodyBB24bodyBB24cloneBB

endBB25:                                          ; preds = %bodyBB24bodyBB24cloneBB, %bodyBB24
  %cmp4.reload = load volatile i1, i1* %cmp4.reg2mem, align 1
  br i1 %cmp4.reload, label %land.rhs, label %land.end

land.rhs:                                         ; preds = %endBB25
  %187 = call { i32, i32 } @llvm.x86.rdrand.32()
  %188 = extractvalue { i32, i32 } %187, 0
  %189 = add i32 %188, 1
  %190 = mul i32 %188, %189
  %191 = mul i32 %188, %188
  %192 = sub i32 %190, %191
  %193 = and i32 %192, 1
  %194 = icmp eq i32 %193, 1
  br i1 %194, label %bodyBB26, label %bodyBB26bodyBB26cloneBB

bodyBB26:                                         ; preds = %bodyBB26bodyBB26cloneBB, %land.rhs
  %dest.reload = load volatile [100 x i8]*, [100 x i8]** %dest.reg2mem, align 8
  %arraydecay5 = getelementptr inbounds [100 x i8], [100 x i8]* %dest.reload, i64 0, i64 0
  store i8* %arraydecay5, i8** %arraydecay5.reg2mem, align 8
  %195 = sub i32 %188, 1
  %196 = add i32 %188, 3
  %197 = add i32 %188, 4
  %198 = sub i32 %188, 3
  %199 = mul i32 %195, %196
  %200 = mul i32 %197, %198
  %201 = sub i32 %199, %200
  %202 = sub i32 %201, 9
  %203 = and i32 %202, 1
  %204 = icmp eq i32 %203, 1
  br i1 %204, label %endBB27, label %bodyBB26bodyBB26cloneBB

endBB27:                                          ; preds = %bodyBB26bodyBB26cloneBB, %bodyBB26
  br label %205

205:                                              ; preds = %endBB27
  %206 = call { i32, i32 } @llvm.x86.rdrand.32()
  %207 = extractvalue { i32, i32 } %206, 0
  %208 = mul i32 %207, 3
  %209 = sub i32 %207, 2
  %210 = mul i32 %208, %209
  %211 = mul i32 %207, %207
  %212 = mul i32 %211, 3
  %213 = mul i32 %207, 7
  %214 = sub i32 %210, %212
  %215 = add i32 %213, %214
  %216 = and i32 %215, 1
  %217 = icmp eq i32 %216, 1
  br i1 %217, label %bodyBB28, label %bodyBB28bodyBB28cloneBB

bodyBB28:                                         ; preds = %bodyBB28bodyBB28cloneBB, %205
  %arraydecay5.reload = load volatile i8*, i8** %arraydecay5.reg2mem, align 8
  %call6 = call i32 @memcmp(i8* %arraydecay5.reload, i8* getelementptr inbounds ([100 x i8], [100 x i8]* bitcast (<{ [22 x i8], [78 x i8] }>* @enc to [100 x i8]*), i64 0, i64 0), i64 22) #6
  store i32 %call6, i32* %call6.reg2mem, align 4
  %218 = add i32 %207, 1
  %219 = mul i32 %207, %218
  %220 = mul i32 %207, %207
  %221 = sub i32 %219, %220
  %222 = and i32 %221, 1
  %223 = icmp eq i32 %222, 1
  br i1 %223, label %endBB29, label %bodyBB28bodyBB28cloneBB

endBB29:                                          ; preds = %bodyBB28bodyBB28cloneBB, %bodyBB28
  br label %224

224:                                              ; preds = %endBB29
  %225 = call { i32, i32 } @llvm.x86.rdrand.32()
  %226 = extractvalue { i32, i32 } %225, 0
  %227 = add i32 %226, 1
  %228 = mul i32 %226, %227
  %229 = mul i32 %226, %226
  %230 = sub i32 %228, %229
  %231 = and i32 %230, 1
  %232 = icmp eq i32 %231, 1
  br i1 %232, label %bodyBB30, label %bodyBB30bodyBB30cloneBB

bodyBB30:                                         ; preds = %bodyBB30bodyBB30cloneBB, %224
  %call6.reload = load volatile i32, i32* %call6.reg2mem, align 4
  %tobool = icmp ne i32 %call6.reload, 0
  %lnot = xor i1 %tobool, true
  store i1 %lnot, i1* %lnot.reg2mem, align 1
  %233 = mul i32 %226, 3
  %234 = sub i32 %226, 2
  %235 = mul i32 %233, %234
  %236 = mul i32 %226, %226
  %237 = mul i32 %236, 3
  %238 = mul i32 %226, 7
  %239 = sub i32 %235, %237
  %240 = add i32 %238, %239
  %241 = and i32 %240, 1
  %242 = icmp eq i32 %241, 1
  br i1 %242, label %endBB31, label %bodyBB30bodyBB30cloneBB

endBB31:                                          ; preds = %bodyBB30bodyBB30cloneBB, %bodyBB30
  %lnot.reload = load volatile i1, i1* %lnot.reg2mem, align 1
  br label %land.end

land.end:                                         ; preds = %endBB31, %endBB25
  %243 = phi i1 [ false, %endBB25 ], [ %lnot.reload, %endBB31 ]
  %244 = call { i32, i32 } @llvm.x86.rdrand.32()
  %245 = extractvalue { i32, i32 } %244, 0
  %246 = mul i32 %245, 3
  %247 = sub i32 %245, 2
  %248 = mul i32 %246, %247
  %249 = mul i32 %245, %245
  %250 = mul i32 %249, 3
  %251 = mul i32 %245, 7
  %252 = sub i32 %248, %250
  %253 = add i32 %251, %252
  %254 = and i32 %253, 1
  %255 = icmp eq i32 %254, 1
  br i1 %255, label %bodyBB32, label %bodyBB32bodyBB32cloneBB

bodyBB32:                                         ; preds = %bodyBB32bodyBB32cloneBB, %land.end
  %frombool = zext i1 %243 to i8
  %result.reload7 = load volatile i8*, i8** %result.reg2mem, align 8
  store i8 %frombool, i8* %result.reload7, align 1
  %result.reload = load volatile i8*, i8** %result.reg2mem, align 8
  %256 = load i8, i8* %result.reload, align 1
  %tobool7 = trunc i8 %256 to i1
  store i1 %tobool7, i1* %tobool7.reg2mem, align 1
  %257 = add i32 %245, 1
  %258 = mul i32 %245, %257
  %259 = mul i32 %245, %245
  %260 = sub i32 %258, %259
  %261 = and i32 %260, 1
  %262 = icmp eq i32 %261, 1
  br i1 %262, label %endBB33, label %bodyBB32bodyBB32cloneBB

endBB33:                                          ; preds = %bodyBB32bodyBB32cloneBB, %bodyBB32
  %tobool7.reload = load volatile i1, i1* %tobool7.reg2mem, align 1
  br i1 %tobool7.reload, label %if.then8, label %if.else

if.then8:                                         ; preds = %endBB33
  %263 = call { i32, i32 } @llvm.x86.rdrand.32()
  %264 = extractvalue { i32, i32 } %263, 0
  %265 = add i32 %264, 1
  %266 = mul i32 %264, %265
  %267 = mul i32 %264, %264
  %268 = sub i32 %266, %267
  %269 = and i32 %268, 1
  %270 = icmp eq i32 %269, 1
  br i1 %270, label %bodyBB34, label %bodyBB34bodyBB34cloneBB

bodyBB34:                                         ; preds = %bodyBB34bodyBB34cloneBB, %if.then8
  %271 = mul i32 %264, 3
  %272 = sub i32 %264, 2
  %273 = mul i32 %271, %272
  %274 = mul i32 %264, %264
  %275 = mul i32 %274, 3
  %276 = mul i32 %264, 7
  %277 = sub i32 %273, %275
  %278 = add i32 %276, %277
  %279 = and i32 %278, 1
  %280 = icmp eq i32 %279, 1
  br i1 %280, label %endBB35, label %bodyBB34bodyBB34cloneBB

endBB35:                                          ; preds = %bodyBB34bodyBB34cloneBB, %bodyBB34
  br label %281

281:                                              ; preds = %endBB35
  %282 = call { i32, i32 } @llvm.x86.rdrand.32()
  %283 = extractvalue { i32, i32 } %282, 0
  %284 = add i32 %283, 1
  %285 = mul i32 %283, %284
  %286 = mul i32 %283, %283
  %287 = sub i32 %285, %286
  %288 = and i32 %287, 1
  %289 = icmp eq i32 %288, 1
  br i1 %289, label %bodyBB36, label %bodyBB36bodyBB36cloneBB

bodyBB36:                                         ; preds = %bodyBB36bodyBB36cloneBB, %281
  %290 = sub i32 %283, 1
  %291 = add i32 %283, 3
  %292 = add i32 %283, 4
  %293 = sub i32 %283, 3
  %294 = mul i32 %290, %291
  %295 = mul i32 %292, %293
  %296 = sub i32 %294, %295
  %297 = sub i32 %296, 9
  %298 = and i32 %297, 1
  %299 = icmp eq i32 %298, 1
  br i1 %299, label %endBB37, label %bodyBB36bodyBB36cloneBB

endBB37:                                          ; preds = %bodyBB36bodyBB36cloneBB, %bodyBB36
  br label %300

300:                                              ; preds = %endBB37
  %301 = call { i32, i32 } @llvm.x86.rdrand.32()
  %302 = extractvalue { i32, i32 } %301, 0
  %303 = add i32 %302, 1
  %304 = mul i32 %302, %303
  %305 = mul i32 %302, %302
  %306 = sub i32 %304, %305
  %307 = and i32 %306, 1
  %308 = icmp eq i32 %307, 1
  br i1 %308, label %bodyBB38, label %bodyBB38bodyBB38cloneBB

bodyBB38:                                         ; preds = %bodyBB38bodyBB38cloneBB, %300
  %call9 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([18 x i8], [18 x i8]* @.str.3, i64 0, i64 0))
  %309 = mul i32 %302, 3
  %310 = sub i32 %302, 2
  %311 = mul i32 %309, %310
  %312 = mul i32 %302, %302
  %313 = mul i32 %312, 3
  %314 = mul i32 %302, 7
  %315 = sub i32 %311, %313
  %316 = add i32 %314, %315
  %317 = and i32 %316, 1
  %318 = icmp eq i32 %317, 1
  br i1 %318, label %endBB39, label %bodyBB38bodyBB38cloneBB

endBB39:                                          ; preds = %bodyBB38bodyBB38cloneBB, %bodyBB38
  br label %if.end11

if.else:                                          ; preds = %endBB33
  %319 = call { i32, i32 } @llvm.x86.rdrand.32()
  %320 = extractvalue { i32, i32 } %319, 0
  %321 = sub i32 %320, 1
  %322 = add i32 %320, 3
  %323 = add i32 %320, 4
  %324 = sub i32 %320, 3
  %325 = mul i32 %321, %322
  %326 = mul i32 %323, %324
  %327 = sub i32 %325, %326
  %328 = sub i32 %327, 9
  %329 = and i32 %328, 1
  %330 = icmp eq i32 %329, 1
  br i1 %330, label %bodyBB40, label %bodyBB40bodyBB40cloneBB

bodyBB40:                                         ; preds = %bodyBB40bodyBB40cloneBB, %if.else
  %331 = sub i32 %320, 1
  %332 = add i32 %320, 3
  %333 = add i32 %320, 4
  %334 = sub i32 %320, 3
  %335 = mul i32 %331, %332
  %336 = mul i32 %333, %334
  %337 = sub i32 %335, %336
  %338 = sub i32 %337, 9
  %339 = and i32 %338, 1
  %340 = icmp eq i32 %339, 1
  br i1 %340, label %endBB41, label %bodyBB40bodyBB40cloneBB

endBB41:                                          ; preds = %bodyBB40bodyBB40cloneBB, %bodyBB40
  br label %341

341:                                              ; preds = %endBB41
  %342 = call { i32, i32 } @llvm.x86.rdrand.32()
  %343 = extractvalue { i32, i32 } %342, 0
  %344 = mul i32 %343, 3
  %345 = sub i32 %343, 2
  %346 = mul i32 %344, %345
  %347 = mul i32 %343, %343
  %348 = mul i32 %347, 3
  %349 = mul i32 %343, 7
  %350 = sub i32 %346, %348
  %351 = add i32 %349, %350
  %352 = and i32 %351, 1
  %353 = icmp eq i32 %352, 1
  br i1 %353, label %bodyBB42, label %bodyBB42bodyBB42cloneBB

bodyBB42:                                         ; preds = %bodyBB42bodyBB42cloneBB, %341
  %354 = sub i32 %343, 1
  %355 = add i32 %343, 3
  %356 = add i32 %343, 4
  %357 = sub i32 %343, 3
  %358 = mul i32 %354, %355
  %359 = mul i32 %356, %357
  %360 = sub i32 %358, %359
  %361 = sub i32 %360, 9
  %362 = and i32 %361, 1
  %363 = icmp eq i32 %362, 1
  br i1 %363, label %endBB43, label %bodyBB42bodyBB42cloneBB

endBB43:                                          ; preds = %bodyBB42bodyBB42cloneBB, %bodyBB42
  br label %364

364:                                              ; preds = %endBB43
  %365 = call { i32, i32 } @llvm.x86.rdrand.32()
  %366 = extractvalue { i32, i32 } %365, 0
  %367 = mul i32 %366, 3
  %368 = sub i32 %366, 2
  %369 = mul i32 %367, %368
  %370 = mul i32 %366, %366
  %371 = mul i32 %370, 3
  %372 = mul i32 %366, 7
  %373 = sub i32 %369, %371
  %374 = add i32 %372, %373
  %375 = and i32 %374, 1
  %376 = icmp eq i32 %375, 1
  br i1 %376, label %bodyBB44, label %bodyBB44bodyBB44cloneBB

bodyBB44:                                         ; preds = %bodyBB44bodyBB44cloneBB, %364
  %call10 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([18 x i8], [18 x i8]* @.str.4, i64 0, i64 0))
  %377 = mul i32 %366, 3
  %378 = sub i32 %366, 2
  %379 = mul i32 %377, %378
  %380 = mul i32 %366, %366
  %381 = mul i32 %380, 3
  %382 = mul i32 %366, 7
  %383 = sub i32 %379, %381
  %384 = add i32 %382, %383
  %385 = and i32 %384, 1
  %386 = icmp eq i32 %385, 1
  br i1 %386, label %endBB45, label %bodyBB44bodyBB44cloneBB

endBB45:                                          ; preds = %bodyBB44bodyBB44cloneBB, %bodyBB44
  br label %if.end11

if.end11:                                         ; preds = %endBB45, %endBB39, %endBB17
  %387 = call { i32, i32 } @llvm.x86.rdrand.32()
  %388 = extractvalue { i32, i32 } %387, 0
  %389 = add i32 %388, 1
  %390 = mul i32 %388, %389
  %391 = mul i32 %388, %388
  %392 = sub i32 %390, %391
  %393 = and i32 %392, 1
  %394 = icmp eq i32 %393, 1
  br i1 %394, label %bodyBB46, label %bodyBB46bodyBB46cloneBB

bodyBB46:                                         ; preds = %bodyBB46bodyBB46cloneBB, %if.end11
  %395 = mul i32 %388, 3
  %396 = sub i32 %388, 2
  %397 = mul i32 %395, %396
  %398 = mul i32 %388, %388
  %399 = mul i32 %398, 3
  %400 = mul i32 %388, 7
  %401 = sub i32 %397, %399
  %402 = add i32 %400, %401
  %403 = and i32 %402, 1
  %404 = icmp eq i32 %403, 1
  br i1 %404, label %endBB47, label %bodyBB46bodyBB46cloneBB

endBB47:                                          ; preds = %bodyBB46bodyBB46cloneBB, %bodyBB46
  br label %405

405:                                              ; preds = %endBB47
  %406 = call { i32, i32 } @llvm.x86.rdrand.32()
  %407 = extractvalue { i32, i32 } %406, 0
  %408 = add i32 %407, 1
  %409 = mul i32 %407, %408
  %410 = mul i32 %407, %407
  %411 = sub i32 %409, %410
  %412 = and i32 %411, 1
  %413 = icmp eq i32 %412, 1
  br i1 %413, label %bodyBB48, label %bodyBB48bodyBB48cloneBB

bodyBB48:                                         ; preds = %bodyBB48bodyBB48cloneBB, %405
  %414 = add i32 %407, 1
  %415 = mul i32 %407, %414
  %416 = mul i32 %407, %407
  %417 = sub i32 %415, %416
  %418 = and i32 %417, 1
  %419 = icmp eq i32 %418, 1
  br i1 %419, label %endBB49, label %bodyBB48bodyBB48cloneBB

endBB49:                                          ; preds = %bodyBB48bodyBB48cloneBB, %bodyBB48
  br label %420

420:                                              ; preds = %endBB49
  %421 = call { i32, i32 } @llvm.x86.rdrand.32()
  %422 = extractvalue { i32, i32 } %421, 0
  %423 = mul i32 %422, 3
  %424 = sub i32 %422, 2
  %425 = mul i32 %423, %424
  %426 = mul i32 %422, %422
  %427 = mul i32 %426, 3
  %428 = mul i32 %422, 7
  %429 = sub i32 %425, %427
  %430 = add i32 %428, %429
  %431 = and i32 %430, 1
  %432 = icmp eq i32 %431, 1
  br i1 %432, label %bodyBB50, label %bodyBB50bodyBB50cloneBB

bodyBB50:                                         ; preds = %bodyBB50bodyBB50cloneBB, %420
  %retval.reload = load volatile i32*, i32** %retval.reg2mem, align 8
  %433 = load i32, i32* %retval.reload, align 4
  store i32 %433, i32* %.reg2mem52, align 4
  %434 = sub i32 %422, 1
  %435 = add i32 %422, 3
  %436 = add i32 %422, 4
  %437 = sub i32 %422, 3
  %438 = mul i32 %434, %435
  %439 = mul i32 %436, %437
  %440 = sub i32 %438, %439
  %441 = sub i32 %440, 9
  %442 = and i32 %441, 1
  %443 = icmp eq i32 %442, 1
  br i1 %443, label %endBB51, label %bodyBB50bodyBB50cloneBB

endBB51:                                          ; preds = %bodyBB50bodyBB50cloneBB, %bodyBB50
  %.reload53 = load volatile i32, i32* %.reg2mem52, align 4
  ret i32 %.reload53

bodyBBbodyBBcloneBB:                              ; preds = %bodyBB, %entry
  %retvalbodyBBcloneBB = alloca i32, align 4
  store i32* %retvalbodyBBcloneBB, i32** %retval.reg2mem, align 8
  %argc.addrbodyBBcloneBB = alloca i32, align 4
  store i32* %argc.addrbodyBBcloneBB, i32** %argc.addr.reg2mem, align 8
  %argv.addrbodyBBcloneBB = alloca i8**, align 8
  store i8*** %argv.addrbodyBBcloneBB, i8**** %argv.addr.reg2mem, align 8
  %destbodyBBcloneBB = alloca [100 x i8], align 16
  store [100 x i8]* %destbodyBBcloneBB, [100 x i8]** %dest.reg2mem, align 8
  %resultbodyBBcloneBB = alloca i8, align 1
  store i8* %resultbodyBBcloneBB, i8** %result.reg2mem, align 8
  %444 = sub i32 %1, 1
  %445 = add i32 %1, 3
  %446 = add i32 %1, 4
  %447 = sub i32 %1, 3
  %448 = mul i32 %444, %445
  %449 = mul i32 %446, %447
  %450 = sub i32 %448, %449
  %451 = sub i32 %450, 9
  %452 = and i32 %451, 1
  %453 = icmp eq i32 %452, 1
  br i1 %453, label %bodyBB, label %endBB

bodyBB8bodyBB8cloneBB:                            ; preds = %bodyBB8, %18
  %retval.reload2bodyBB8cloneBB = load volatile i32*, i32** %retval.reg2mem, align 8
  store i32 0, i32* %retval.reload2bodyBB8cloneBB, align 4
  %argc.addr.reload3bodyBB8cloneBB = load volatile i32*, i32** %argc.addr.reg2mem, align 8
  store i32 %argc, i32* %argc.addr.reload3bodyBB8cloneBB, align 4
  %argv.addr.reload4bodyBB8cloneBB = load volatile i8***, i8**** %argv.addr.reg2mem, align 8
  store i8** %argv, i8*** %argv.addr.reload4bodyBB8cloneBB, align 8
  %callbodyBB8cloneBB = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([26 x i8], [26 x i8]* @.str, i64 0, i64 0))
  %argc.addr.reloadbodyBB8cloneBB = load volatile i32*, i32** %argc.addr.reg2mem, align 8
  %454 = load i32, i32* %argc.addr.reloadbodyBB8cloneBB, align 4
  store i32 %454, i32* %.reg2mem, align 4
  %455 = add i32 %20, 1
  %456 = mul i32 %20, %455
  %457 = mul i32 %20, %20
  %458 = sub i32 %456, %457
  %459 = and i32 %458, 1
  %460 = icmp eq i32 %459, 1
  br i1 %460, label %bodyBB8, label %endBB9

bodyBB10bodyBB10cloneBB:                          ; preds = %bodyBB10, %38
  %.reloadbodyBB10cloneBB = load volatile i32, i32* %.reg2mem, align 4
  %cmpbodyBB10cloneBB = icmp sle i32 %.reloadbodyBB10cloneBB, 1
  store i1 %cmpbodyBB10cloneBB, i1* %cmp.reg2mem, align 1
  %461 = sub i32 %40, 1
  %462 = add i32 %40, 3
  %463 = add i32 %40, 4
  %464 = sub i32 %40, 3
  %465 = mul i32 %461, %462
  %466 = mul i32 %463, %464
  %467 = sub i32 %465, %466
  %468 = sub i32 %467, 9
  %469 = and i32 %468, 1
  %470 = icmp eq i32 %469, 1
  br i1 %470, label %bodyBB10, label %endBB11

bodyBB12bodyBB12cloneBB:                          ; preds = %bodyBB12, %if.then
  %471 = sub i32 %58, 1
  %472 = add i32 %58, 3
  %473 = add i32 %58, 4
  %474 = sub i32 %58, 3
  %475 = mul i32 %471, %472
  %476 = mul i32 %473, %474
  %477 = sub i32 %475, %476
  %478 = sub i32 %477, 9
  %479 = and i32 %478, 1
  %480 = icmp eq i32 %479, 1
  br i1 %480, label %bodyBB12, label %endBB13

bodyBB14bodyBB14cloneBB:                          ; preds = %bodyBB14, %79
  %481 = add i32 %81, 1
  %482 = mul i32 %81, %481
  %483 = mul i32 %81, %81
  %484 = sub i32 %482, %483
  %485 = and i32 %484, 1
  %486 = icmp eq i32 %485, 1
  br i1 %486, label %bodyBB14, label %endBB15

bodyBB16bodyBB16cloneBB:                          ; preds = %bodyBB16, %102
  %call1bodyBB16cloneBB = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([33 x i8], [33 x i8]* @.str.1, i64 0, i64 0))
  %retval.reload1bodyBB16cloneBB = load volatile i32*, i32** %retval.reg2mem, align 8
  store i32 0, i32* %retval.reload1bodyBB16cloneBB, align 4
  %487 = mul i32 %104, 3
  %488 = sub i32 %104, 2
  %489 = mul i32 %487, %488
  %490 = mul i32 %104, %104
  %491 = mul i32 %490, 3
  %492 = mul i32 %104, 7
  %493 = sub i32 %489, %491
  %494 = add i32 %492, %493
  %495 = and i32 %494, 1
  %496 = icmp eq i32 %495, 1
  br i1 %496, label %bodyBB16, label %endBB17

bodyBB18bodyBB18cloneBB:                          ; preds = %bodyBB18, %if.end
  %argv.addr.reloadbodyBB18cloneBB = load volatile i8***, i8**** %argv.addr.reg2mem, align 8
  %497 = load i8**, i8*** %argv.addr.reloadbodyBB18cloneBB, align 8
  %arrayidxbodyBB18cloneBB = getelementptr inbounds i8*, i8** %497, i64 1
  %498 = load i8*, i8** %arrayidxbodyBB18cloneBB, align 8
  store i8* %498, i8** @input, align 8
  %499 = load i8*, i8** @input, align 8
  %call2bodyBB18cloneBB = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([18 x i8], [18 x i8]* @.str.2, i64 0, i64 0), i8* %499)
  %500 = sub i32 %126, 1
  %501 = add i32 %126, 3
  %502 = add i32 %126, 4
  %503 = sub i32 %126, 3
  %504 = mul i32 %500, %501
  %505 = mul i32 %502, %503
  %506 = sub i32 %504, %505
  %507 = sub i32 %506, 9
  %508 = and i32 %507, 1
  %509 = icmp eq i32 %508, 1
  br i1 %509, label %bodyBB18, label %endBB19

bodyBB20bodyBB20cloneBB:                          ; preds = %bodyBB20, %146
  %dest.reload6bodyBB20cloneBB = load volatile [100 x i8]*, [100 x i8]** %dest.reg2mem, align 8
  %510 = bitcast [100 x i8]* %dest.reload6bodyBB20cloneBB to i8*
  call void @llvm.memset.p0i8.i64(i8* align 16 %510, i8 0, i64 100, i1 false)
  %dest.reload5bodyBB20cloneBB = load volatile [100 x i8]*, [100 x i8]** %dest.reg2mem, align 8
  %arraydecaybodyBB20cloneBB = getelementptr inbounds [100 x i8], [100 x i8]* %dest.reload5bodyBB20cloneBB, i64 0, i64 0
  %511 = load i8*, i8** @input, align 8
  call void @_Z7encryptPhPc(i8* %arraydecaybodyBB20cloneBB, i8* %511)
  %512 = load i8*, i8** @input, align 8
  store i8* %512, i8** %.reg2mem22, align 8
  %513 = add i32 %148, 1
  %514 = mul i32 %148, %513
  %515 = mul i32 %148, %148
  %516 = sub i32 %514, %515
  %517 = and i32 %516, 1
  %518 = icmp eq i32 %517, 1
  br i1 %518, label %bodyBB20, label %endBB21

bodyBB24bodyBB24cloneBB:                          ; preds = %bodyBB24, %164
  %.reload23bodyBB24cloneBB = load volatile i8*, i8** %.reg2mem22, align 8
  %call3bodyBB24cloneBB = call i64 @strlen(i8* %.reload23bodyBB24cloneBB) #6
  %cmp4bodyBB24cloneBB = icmp eq i64 %call3bodyBB24cloneBB, 22
  store i1 %cmp4bodyBB24cloneBB, i1* %cmp4.reg2mem, align 1
  %519 = mul i32 %166, 3
  %520 = sub i32 %166, 2
  %521 = mul i32 %519, %520
  %522 = mul i32 %166, %166
  %523 = mul i32 %522, 3
  %524 = mul i32 %166, 7
  %525 = sub i32 %521, %523
  %526 = add i32 %524, %525
  %527 = and i32 %526, 1
  %528 = icmp eq i32 %527, 1
  br i1 %528, label %bodyBB24, label %endBB25

bodyBB26bodyBB26cloneBB:                          ; preds = %bodyBB26, %land.rhs
  %dest.reloadbodyBB26cloneBB = load volatile [100 x i8]*, [100 x i8]** %dest.reg2mem, align 8
  %arraydecay5bodyBB26cloneBB = getelementptr inbounds [100 x i8], [100 x i8]* %dest.reloadbodyBB26cloneBB, i64 0, i64 0
  store i8* %arraydecay5bodyBB26cloneBB, i8** %arraydecay5.reg2mem, align 8
  %529 = sub i32 %188, 1
  %530 = add i32 %188, 3
  %531 = add i32 %188, 4
  %532 = sub i32 %188, 3
  %533 = mul i32 %529, %530
  %534 = mul i32 %531, %532
  %535 = sub i32 %533, %534
  %536 = sub i32 %535, 9
  %537 = and i32 %536, 1
  %538 = icmp eq i32 %537, 1
  br i1 %538, label %bodyBB26, label %endBB27

bodyBB28bodyBB28cloneBB:                          ; preds = %bodyBB28, %205
  %arraydecay5.reloadbodyBB28cloneBB = load volatile i8*, i8** %arraydecay5.reg2mem, align 8
  %call6bodyBB28cloneBB = call i32 @memcmp(i8* %arraydecay5.reloadbodyBB28cloneBB, i8* getelementptr inbounds ([100 x i8], [100 x i8]* bitcast (<{ [22 x i8], [78 x i8] }>* @enc to [100 x i8]*), i64 0, i64 0), i64 22) #6
  store i32 %call6bodyBB28cloneBB, i32* %call6.reg2mem, align 4
  %539 = add i32 %207, 1
  %540 = mul i32 %207, %539
  %541 = mul i32 %207, %207
  %542 = sub i32 %540, %541
  %543 = and i32 %542, 1
  %544 = icmp eq i32 %543, 1
  br i1 %544, label %bodyBB28, label %endBB29

bodyBB30bodyBB30cloneBB:                          ; preds = %bodyBB30, %224
  %call6.reloadbodyBB30cloneBB = load volatile i32, i32* %call6.reg2mem, align 4
  %toboolbodyBB30cloneBB = icmp ne i32 %call6.reloadbodyBB30cloneBB, 0
  %lnotbodyBB30cloneBB = xor i1 %toboolbodyBB30cloneBB, true
  store i1 %lnotbodyBB30cloneBB, i1* %lnot.reg2mem, align 1
  %545 = sub i32 %226, 1
  %546 = add i32 %226, 3
  %547 = add i32 %226, 4
  %548 = sub i32 %226, 3
  %549 = mul i32 %545, %546
  %550 = mul i32 %547, %548
  %551 = sub i32 %549, %550
  %552 = sub i32 %551, 9
  %553 = and i32 %552, 1
  %554 = icmp eq i32 %553, 1
  br i1 %554, label %bodyBB30, label %endBB31

bodyBB32bodyBB32cloneBB:                          ; preds = %bodyBB32, %land.end
  %fromboolbodyBB32cloneBB = zext i1 %243 to i8
  %result.reload7bodyBB32cloneBB = load volatile i8*, i8** %result.reg2mem, align 8
  store i8 %fromboolbodyBB32cloneBB, i8* %result.reload7bodyBB32cloneBB, align 1
  %result.reloadbodyBB32cloneBB = load volatile i8*, i8** %result.reg2mem, align 8
  %555 = load i8, i8* %result.reloadbodyBB32cloneBB, align 1
  %tobool7bodyBB32cloneBB = trunc i8 %555 to i1
  store i1 %tobool7bodyBB32cloneBB, i1* %tobool7.reg2mem, align 1
  %556 = sub i32 %245, 1
  %557 = add i32 %245, 3
  %558 = add i32 %245, 4
  %559 = sub i32 %245, 3
  %560 = mul i32 %556, %557
  %561 = mul i32 %558, %559
  %562 = sub i32 %560, %561
  %563 = sub i32 %562, 9
  %564 = and i32 %563, 1
  %565 = icmp eq i32 %564, 1
  br i1 %565, label %bodyBB32, label %endBB33

bodyBB34bodyBB34cloneBB:                          ; preds = %bodyBB34, %if.then8
  %566 = sub i32 %264, 1
  %567 = add i32 %264, 3
  %568 = add i32 %264, 4
  %569 = sub i32 %264, 3
  %570 = mul i32 %566, %567
  %571 = mul i32 %568, %569
  %572 = sub i32 %570, %571
  %573 = sub i32 %572, 9
  %574 = and i32 %573, 1
  %575 = icmp eq i32 %574, 1
  br i1 %575, label %bodyBB34, label %endBB35

bodyBB36bodyBB36cloneBB:                          ; preds = %bodyBB36, %281
  %576 = sub i32 %283, 1
  %577 = add i32 %283, 3
  %578 = add i32 %283, 4
  %579 = sub i32 %283, 3
  %580 = mul i32 %576, %577
  %581 = mul i32 %578, %579
  %582 = sub i32 %580, %581
  %583 = sub i32 %582, 9
  %584 = and i32 %583, 1
  %585 = icmp eq i32 %584, 1
  br i1 %585, label %bodyBB36, label %endBB37

bodyBB38bodyBB38cloneBB:                          ; preds = %bodyBB38, %300
  %call9bodyBB38cloneBB = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([18 x i8], [18 x i8]* @.str.3, i64 0, i64 0))
  %586 = add i32 %302, 1
  %587 = mul i32 %302, %586
  %588 = mul i32 %302, %302
  %589 = sub i32 %587, %588
  %590 = and i32 %589, 1
  %591 = icmp eq i32 %590, 1
  br i1 %591, label %bodyBB38, label %endBB39

bodyBB40bodyBB40cloneBB:                          ; preds = %bodyBB40, %if.else
  %592 = sub i32 %320, 1
  %593 = add i32 %320, 3
  %594 = add i32 %320, 4
  %595 = sub i32 %320, 3
  %596 = mul i32 %592, %593
  %597 = mul i32 %594, %595
  %598 = sub i32 %596, %597
  %599 = sub i32 %598, 9
  %600 = and i32 %599, 1
  %601 = icmp eq i32 %600, 1
  br i1 %601, label %bodyBB40, label %endBB41

bodyBB42bodyBB42cloneBB:                          ; preds = %bodyBB42, %341
  %602 = add i32 %343, 1
  %603 = mul i32 %343, %602
  %604 = mul i32 %343, %343
  %605 = sub i32 %603, %604
  %606 = and i32 %605, 1
  %607 = icmp eq i32 %606, 1
  br i1 %607, label %bodyBB42, label %endBB43

bodyBB44bodyBB44cloneBB:                          ; preds = %bodyBB44, %364
  %call10bodyBB44cloneBB = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([18 x i8], [18 x i8]* @.str.4, i64 0, i64 0))
  %608 = mul i32 %366, 3
  %609 = sub i32 %366, 2
  %610 = mul i32 %608, %609
  %611 = mul i32 %366, %366
  %612 = mul i32 %611, 3
  %613 = mul i32 %366, 7
  %614 = sub i32 %610, %612
  %615 = add i32 %613, %614
  %616 = and i32 %615, 1
  %617 = icmp eq i32 %616, 1
  br i1 %617, label %bodyBB44, label %endBB45

bodyBB46bodyBB46cloneBB:                          ; preds = %bodyBB46, %if.end11
  %618 = mul i32 %388, 3
  %619 = sub i32 %388, 2
  %620 = mul i32 %618, %619
  %621 = mul i32 %388, %388
  %622 = mul i32 %621, 3
  %623 = mul i32 %388, 7
  %624 = sub i32 %620, %622
  %625 = add i32 %623, %624
  %626 = and i32 %625, 1
  %627 = icmp eq i32 %626, 1
  br i1 %627, label %bodyBB46, label %endBB47

bodyBB48bodyBB48cloneBB:                          ; preds = %bodyBB48, %405
  %628 = sub i32 %407, 1
  %629 = add i32 %407, 3
  %630 = add i32 %407, 4
  %631 = sub i32 %407, 3
  %632 = mul i32 %628, %629
  %633 = mul i32 %630, %631
  %634 = sub i32 %632, %633
  %635 = sub i32 %634, 9
  %636 = and i32 %635, 1
  %637 = icmp eq i32 %636, 1
  br i1 %637, label %bodyBB48, label %endBB49

bodyBB50bodyBB50cloneBB:                          ; preds = %bodyBB50, %420
  %retval.reloadbodyBB50cloneBB = load volatile i32*, i32** %retval.reg2mem, align 8
  %638 = load i32, i32* %retval.reloadbodyBB50cloneBB, align 4
  store i32 %638, i32* %.reg2mem52, align 4
  %639 = mul i32 %422, 3
  %640 = sub i32 %422, 2
  %641 = mul i32 %639, %640
  %642 = mul i32 %422, %422
  %643 = mul i32 %642, 3
  %644 = mul i32 %422, 7
  %645 = sub i32 %641, %643
  %646 = add i32 %644, %645
  %647 = and i32 %646, 1
  %648 = icmp eq i32 %647, 1
  br i1 %648, label %bodyBB50, label %endBB51
}

declare dso_local i32 @printf(i8*, ...) #3

; Function Attrs: argmemonly nofree nosync nounwind willreturn writeonly
declare void @llvm.memset.p0i8.i64(i8* nocapture writeonly, i8, i64, i1 immarg) #4

; Function Attrs: nounwind readonly willreturn
declare dso_local i32 @memcmp(i8*, i8*, i64) #1

; Function Attrs: nounwind
declare { i32, i32 } @llvm.x86.rdrand.32() #5

attributes #0 = { noinline nounwind optnone uwtable mustprogress "disable-tail-calls"="false" "frame-pointer"="all" "less-precise-fpmad"="false" "min-legal-vector-width"="0" "no-infs-fp-math"="false" "no-jump-tables"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #1 = { nounwind readonly willreturn "disable-tail-calls"="false" "frame-pointer"="all" "less-precise-fpmad"="false" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #2 = { noinline norecurse optnone uwtable mustprogress "disable-tail-calls"="false" "frame-pointer"="all" "less-precise-fpmad"="false" "min-legal-vector-width"="0" "no-infs-fp-math"="false" "no-jump-tables"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #3 = { "disable-tail-calls"="false" "frame-pointer"="all" "less-precise-fpmad"="false" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #4 = { argmemonly nofree nosync nounwind willreturn writeonly }
attributes #5 = { nounwind }
attributes #6 = { nounwind readonly willreturn }

!llvm.module.flags = !{!0}
!llvm.ident = !{!1}

!0 = !{i32 1, !"wchar_size", i32 4}
!1 = !{!"clang version 12.0.1"}
!2 = distinct !{!2, !3}
!3 = !{!"llvm.loop.mustprogress"}
