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
  %2 = sub i32 %1, 1
  %3 = add i32 %1, 3
  %4 = add i32 %1, 4
  %5 = sub i32 %1, 3
  %6 = mul i32 %2, %3
  %7 = mul i32 %4, %5
  %8 = sub i32 %6, %7
  %9 = sub i32 %8, 9
  %10 = and i32 %9, 1
  %11 = icmp eq i32 %10, 1
  br i1 %11, label %bodyBB, label %bodyBBbodyBBcloneBB

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
  %12 = sub i32 %1, 1
  %13 = add i32 %1, 3
  %14 = add i32 %1, 4
  %15 = sub i32 %1, 3
  %16 = mul i32 %12, %13
  %17 = mul i32 %14, %15
  %18 = sub i32 %16, %17
  %19 = sub i32 %18, 9
  %20 = and i32 %19, 1
  %21 = icmp eq i32 %20, 1
  br i1 %21, label %endBB, label %bodyBBbodyBBcloneBB

endBB:                                            ; preds = %bodyBBbodyBBcloneBB, %bodyBB
  br label %22

22:                                               ; preds = %endBB
  %23 = call { i32, i32 } @llvm.x86.rdrand.32()
  %24 = extractvalue { i32, i32 } %23, 0
  %25 = mul i32 %24, 3
  %26 = sub i32 %24, 2
  %27 = mul i32 %25, %26
  %28 = mul i32 %24, %24
  %29 = mul i32 %28, 3
  %30 = mul i32 %24, 7
  %31 = sub i32 %27, %29
  %32 = add i32 %30, %31
  %33 = and i32 %32, 1
  %34 = icmp eq i32 %33, 1
  br i1 %34, label %bodyBB12, label %bodyBB12bodyBB12cloneBB

bodyBB12:                                         ; preds = %bodyBB12bodyBB12cloneBB, %22
  %src.addr.reload3 = load volatile i8**, i8*** %src.addr.reg2mem, align 8
  store i8* %src, i8** %src.addr.reload3, align 8
  %src.addr.reload2 = load volatile i8**, i8*** %src.addr.reg2mem, align 8
  %35 = load i8*, i8** %src.addr.reload2, align 8
  %call = call i64 @strlen(i8* %35) #6
  %conv = trunc i64 %call to i32
  %len.reload4 = load volatile i32*, i32** %len.reg2mem, align 8
  store i32 %conv, i32* %len.reload4, align 4
  %36 = mul i32 %24, 3
  %37 = sub i32 %24, 2
  %38 = mul i32 %36, %37
  %39 = mul i32 %24, %24
  %40 = mul i32 %39, 3
  %41 = mul i32 %24, 7
  %42 = sub i32 %38, %40
  %43 = add i32 %41, %42
  %44 = and i32 %43, 1
  %45 = icmp eq i32 %44, 1
  br i1 %45, label %endBB13, label %bodyBB12bodyBB12cloneBB

endBB13:                                          ; preds = %bodyBB12bodyBB12cloneBB, %bodyBB12
  br label %46

46:                                               ; preds = %endBB13
  %47 = call { i32, i32 } @llvm.x86.rdrand.32()
  %48 = extractvalue { i32, i32 } %47, 0
  %49 = mul i32 %48, 3
  %50 = sub i32 %48, 2
  %51 = mul i32 %49, %50
  %52 = mul i32 %48, %48
  %53 = mul i32 %52, 3
  %54 = mul i32 %48, 7
  %55 = sub i32 %51, %53
  %56 = add i32 %54, %55
  %57 = and i32 %56, 1
  %58 = icmp eq i32 %57, 1
  br i1 %58, label %bodyBB14, label %bodyBB14bodyBB14cloneBB

bodyBB14:                                         ; preds = %bodyBB14bodyBB14cloneBB, %46
  %i.reload11 = load volatile i32*, i32** %i.reg2mem, align 8
  store i32 0, i32* %i.reload11, align 4
  %59 = mul i32 %48, 3
  %60 = sub i32 %48, 2
  %61 = mul i32 %59, %60
  %62 = mul i32 %48, %48
  %63 = mul i32 %62, 3
  %64 = mul i32 %48, 7
  %65 = sub i32 %61, %63
  %66 = add i32 %64, %65
  %67 = and i32 %66, 1
  %68 = icmp eq i32 %67, 1
  br i1 %68, label %endBB15, label %bodyBB14bodyBB14cloneBB

endBB15:                                          ; preds = %bodyBB14bodyBB14cloneBB, %bodyBB14
  br label %for.cond

for.cond:                                         ; preds = %endBB37, %endBB15
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
  br i1 %80, label %bodyBB16, label %bodyBB16bodyBB16cloneBB

bodyBB16:                                         ; preds = %bodyBB16bodyBB16cloneBB, %for.cond
  %i.reload10 = load volatile i32*, i32** %i.reg2mem, align 8
  %81 = load i32, i32* %i.reload10, align 4
  store i32 %81, i32* %.reg2mem, align 4
  %82 = add i32 %70, 1
  %83 = mul i32 %70, %82
  %84 = mul i32 %70, %70
  %85 = sub i32 %83, %84
  %86 = and i32 %85, 1
  %87 = icmp eq i32 %86, 1
  br i1 %87, label %endBB17, label %bodyBB16bodyBB16cloneBB

endBB17:                                          ; preds = %bodyBB16bodyBB16cloneBB, %bodyBB16
  br label %88

88:                                               ; preds = %endBB17
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
  br i1 %100, label %bodyBB18, label %bodyBB18bodyBB18cloneBB

bodyBB18:                                         ; preds = %bodyBB18bodyBB18cloneBB, %88
  %len.reload = load volatile i32*, i32** %len.reg2mem, align 8
  %101 = load i32, i32* %len.reload, align 4
  store i32 %101, i32* %.reg2mem20, align 4
  %102 = add i32 %90, 1
  %103 = mul i32 %90, %102
  %104 = mul i32 %90, %90
  %105 = sub i32 %103, %104
  %106 = and i32 %105, 1
  %107 = icmp eq i32 %106, 1
  br i1 %107, label %endBB19, label %bodyBB18bodyBB18cloneBB

endBB19:                                          ; preds = %bodyBB18bodyBB18cloneBB, %bodyBB18
  br label %108

108:                                              ; preds = %endBB19
  %109 = call { i32, i32 } @llvm.x86.rdrand.32()
  %110 = extractvalue { i32, i32 } %109, 0
  %111 = sub i32 %110, 1
  %112 = add i32 %110, 3
  %113 = add i32 %110, 4
  %114 = sub i32 %110, 3
  %115 = mul i32 %111, %112
  %116 = mul i32 %113, %114
  %117 = sub i32 %115, %116
  %118 = sub i32 %117, 9
  %119 = and i32 %118, 1
  %120 = icmp eq i32 %119, 1
  br i1 %120, label %bodyBB22, label %bodyBB22bodyBB22cloneBB

bodyBB22:                                         ; preds = %bodyBB22bodyBB22cloneBB, %108
  %.reload = load volatile i32, i32* %.reg2mem, align 4
  %.reload21 = load volatile i32, i32* %.reg2mem20, align 4
  %cmp = icmp slt i32 %.reload, %.reload21
  store i1 %cmp, i1* %cmp.reg2mem, align 1
  %121 = sub i32 %110, 1
  %122 = add i32 %110, 3
  %123 = add i32 %110, 4
  %124 = sub i32 %110, 3
  %125 = mul i32 %121, %122
  %126 = mul i32 %123, %124
  %127 = sub i32 %125, %126
  %128 = sub i32 %127, 9
  %129 = and i32 %128, 1
  %130 = icmp eq i32 %129, 1
  br i1 %130, label %endBB23, label %bodyBB22bodyBB22cloneBB

endBB23:                                          ; preds = %bodyBB22bodyBB22cloneBB, %bodyBB22
  %cmp.reload = load volatile i1, i1* %cmp.reg2mem, align 1
  br i1 %cmp.reload, label %for.body, label %for.end

for.body:                                         ; preds = %endBB23
  %131 = call { i32, i32 } @llvm.x86.rdrand.32()
  %132 = extractvalue { i32, i32 } %131, 0
  %133 = mul i32 %132, 3
  %134 = sub i32 %132, 2
  %135 = mul i32 %133, %134
  %136 = mul i32 %132, %132
  %137 = mul i32 %136, 3
  %138 = mul i32 %132, 7
  %139 = sub i32 %135, %137
  %140 = add i32 %138, %139
  %141 = and i32 %140, 1
  %142 = icmp eq i32 %141, 1
  br i1 %142, label %bodyBB24, label %bodyBB24bodyBB24cloneBB

bodyBB24:                                         ; preds = %bodyBB24bodyBB24cloneBB, %for.body
  %src.addr.reload = load volatile i8**, i8*** %src.addr.reg2mem, align 8
  %143 = load i8*, i8** %src.addr.reload, align 8
  %i.reload9 = load volatile i32*, i32** %i.reg2mem, align 8
  %144 = load i32, i32* %i.reload9, align 4
  %idxprom = sext i32 %144 to i64
  %arrayidx = getelementptr inbounds i8, i8* %143, i64 %idxprom
  %145 = load i8, i8* %arrayidx, align 1
  %conv1 = sext i8 %145 to i32
  store i32 %conv1, i32* %conv1.reg2mem, align 4
  %i.reload8 = load volatile i32*, i32** %i.reg2mem, align 8
  %146 = load i32, i32* %i.reload8, align 4
  %sub = sub nsw i32 32, %146
  store i32 %sub, i32* %sub.reg2mem, align 4
  %147 = add i32 %132, 1
  %148 = mul i32 %132, %147
  %149 = mul i32 %132, %132
  %150 = sub i32 %148, %149
  %151 = and i32 %150, 1
  %152 = icmp eq i32 %151, 1
  br i1 %152, label %endBB25, label %bodyBB24bodyBB24cloneBB

endBB25:                                          ; preds = %bodyBB24bodyBB24cloneBB, %bodyBB24
  br label %153

153:                                              ; preds = %endBB25
  %154 = call { i32, i32 } @llvm.x86.rdrand.32()
  %155 = extractvalue { i32, i32 } %154, 0
  %156 = add i32 %155, 1
  %157 = mul i32 %155, %156
  %158 = mul i32 %155, %155
  %159 = sub i32 %157, %158
  %160 = and i32 %159, 1
  %161 = icmp eq i32 %160, 1
  br i1 %161, label %bodyBB26, label %bodyBB26bodyBB26cloneBB

bodyBB26:                                         ; preds = %bodyBB26bodyBB26cloneBB, %153
  %conv1.reload = load volatile i32, i32* %conv1.reg2mem, align 4
  %sub.reload = load volatile i32, i32* %sub.reg2mem, align 4
  %add = add nsw i32 %conv1.reload, %sub.reload
  %i.reload7 = load volatile i32*, i32** %i.reg2mem, align 8
  %162 = load i32, i32* %i.reload7, align 4
  %xor = xor i32 %add, %162
  %conv2 = trunc i32 %xor to i8
  store i8 %conv2, i8* %conv2.reg2mem, align 1
  %dest.addr.reload = load volatile i8**, i8*** %dest.addr.reg2mem, align 8
  %163 = load i8*, i8** %dest.addr.reload, align 8
  %i.reload6 = load volatile i32*, i32** %i.reg2mem, align 8
  %164 = load i32, i32* %i.reload6, align 4
  %idxprom3 = sext i32 %164 to i64
  %arrayidx4 = getelementptr inbounds i8, i8* %163, i64 %idxprom3
  store i8* %arrayidx4, i8** %arrayidx4.reg2mem, align 8
  %165 = mul i32 %155, 3
  %166 = sub i32 %155, 2
  %167 = mul i32 %165, %166
  %168 = mul i32 %155, %155
  %169 = mul i32 %168, 3
  %170 = mul i32 %155, 7
  %171 = sub i32 %167, %169
  %172 = add i32 %170, %171
  %173 = and i32 %172, 1
  %174 = icmp eq i32 %173, 1
  br i1 %174, label %endBB27, label %bodyBB26bodyBB26cloneBB

endBB27:                                          ; preds = %bodyBB26bodyBB26cloneBB, %bodyBB26
  br label %175

175:                                              ; preds = %endBB27
  %176 = call { i32, i32 } @llvm.x86.rdrand.32()
  %177 = extractvalue { i32, i32 } %176, 0
  %178 = add i32 %177, 1
  %179 = mul i32 %177, %178
  %180 = mul i32 %177, %177
  %181 = sub i32 %179, %180
  %182 = and i32 %181, 1
  %183 = icmp eq i32 %182, 1
  br i1 %183, label %bodyBB28, label %bodyBB28bodyBB28cloneBB

bodyBB28:                                         ; preds = %bodyBB28bodyBB28cloneBB, %175
  %conv2.reload = load volatile i8, i8* %conv2.reg2mem, align 1
  %arrayidx4.reload = load volatile i8*, i8** %arrayidx4.reg2mem, align 8
  store i8 %conv2.reload, i8* %arrayidx4.reload, align 1
  %184 = sub i32 %177, 1
  %185 = add i32 %177, 3
  %186 = add i32 %177, 4
  %187 = sub i32 %177, 3
  %188 = mul i32 %184, %185
  %189 = mul i32 %186, %187
  %190 = sub i32 %188, %189
  %191 = sub i32 %190, 9
  %192 = and i32 %191, 1
  %193 = icmp eq i32 %192, 1
  br i1 %193, label %endBB29, label %bodyBB28bodyBB28cloneBB

endBB29:                                          ; preds = %bodyBB28bodyBB28cloneBB, %bodyBB28
  br label %for.inc

for.inc:                                          ; preds = %endBB29
  %194 = call { i32, i32 } @llvm.x86.rdrand.32()
  %195 = extractvalue { i32, i32 } %194, 0
  %196 = add i32 %195, 1
  %197 = mul i32 %195, %196
  %198 = mul i32 %195, %195
  %199 = sub i32 %197, %198
  %200 = and i32 %199, 1
  %201 = icmp eq i32 %200, 1
  br i1 %201, label %bodyBB30, label %bodyBB30bodyBB30cloneBB

bodyBB30:                                         ; preds = %bodyBB30bodyBB30cloneBB, %for.inc
  %i.reload5 = load volatile i32*, i32** %i.reg2mem, align 8
  %202 = load i32, i32* %i.reload5, align 4
  store i32 %202, i32* %.reg2mem32, align 4
  %203 = add i32 %195, 1
  %204 = mul i32 %195, %203
  %205 = mul i32 %195, %195
  %206 = sub i32 %204, %205
  %207 = and i32 %206, 1
  %208 = icmp eq i32 %207, 1
  br i1 %208, label %endBB31, label %bodyBB30bodyBB30cloneBB

endBB31:                                          ; preds = %bodyBB30bodyBB30cloneBB, %bodyBB30
  br label %209

209:                                              ; preds = %endBB31
  %210 = call { i32, i32 } @llvm.x86.rdrand.32()
  %211 = extractvalue { i32, i32 } %210, 0
  %212 = mul i32 %211, 3
  %213 = sub i32 %211, 2
  %214 = mul i32 %212, %213
  %215 = mul i32 %211, %211
  %216 = mul i32 %215, 3
  %217 = mul i32 %211, 7
  %218 = sub i32 %214, %216
  %219 = add i32 %217, %218
  %220 = and i32 %219, 1
  %221 = icmp eq i32 %220, 1
  br i1 %221, label %bodyBB34, label %bodyBB34bodyBB34cloneBB

bodyBB34:                                         ; preds = %bodyBB34bodyBB34cloneBB, %209
  %.reload33 = load volatile i32, i32* %.reg2mem32, align 4
  %inc = add nsw i32 %.reload33, 1
  store i32 %inc, i32* %inc.reg2mem, align 4
  %222 = sub i32 %211, 1
  %223 = add i32 %211, 3
  %224 = add i32 %211, 4
  %225 = sub i32 %211, 3
  %226 = mul i32 %222, %223
  %227 = mul i32 %224, %225
  %228 = sub i32 %226, %227
  %229 = sub i32 %228, 9
  %230 = and i32 %229, 1
  %231 = icmp eq i32 %230, 1
  br i1 %231, label %endBB35, label %bodyBB34bodyBB34cloneBB

endBB35:                                          ; preds = %bodyBB34bodyBB34cloneBB, %bodyBB34
  br label %232

232:                                              ; preds = %endBB35
  %233 = call { i32, i32 } @llvm.x86.rdrand.32()
  %234 = extractvalue { i32, i32 } %233, 0
  %235 = add i32 %234, 1
  %236 = mul i32 %234, %235
  %237 = mul i32 %234, %234
  %238 = sub i32 %236, %237
  %239 = and i32 %238, 1
  %240 = icmp eq i32 %239, 1
  br i1 %240, label %bodyBB36, label %bodyBB36bodyBB36cloneBB

bodyBB36:                                         ; preds = %bodyBB36bodyBB36cloneBB, %232
  %i.reload = load volatile i32*, i32** %i.reg2mem, align 8
  %inc.reload = load volatile i32, i32* %inc.reg2mem, align 4
  store i32 %inc.reload, i32* %i.reload, align 4
  %241 = mul i32 %234, 3
  %242 = sub i32 %234, 2
  %243 = mul i32 %241, %242
  %244 = mul i32 %234, %234
  %245 = mul i32 %244, 3
  %246 = mul i32 %234, 7
  %247 = sub i32 %243, %245
  %248 = add i32 %246, %247
  %249 = and i32 %248, 1
  %250 = icmp eq i32 %249, 1
  br i1 %250, label %endBB37, label %bodyBB36bodyBB36cloneBB

endBB37:                                          ; preds = %bodyBB36bodyBB36cloneBB, %bodyBB36
  br label %for.cond, !llvm.loop !2

for.end:                                          ; preds = %endBB23
  %251 = call { i32, i32 } @llvm.x86.rdrand.32()
  %252 = extractvalue { i32, i32 } %251, 0
  %253 = add i32 %252, 1
  %254 = mul i32 %252, %253
  %255 = mul i32 %252, %252
  %256 = sub i32 %254, %255
  %257 = and i32 %256, 1
  %258 = icmp eq i32 %257, 1
  br i1 %258, label %bodyBB38, label %bodyBB38bodyBB38cloneBB

bodyBB38:                                         ; preds = %bodyBB38bodyBB38cloneBB, %for.end
  %259 = add i32 %252, 1
  %260 = mul i32 %252, %259
  %261 = mul i32 %252, %252
  %262 = sub i32 %260, %261
  %263 = and i32 %262, 1
  %264 = icmp eq i32 %263, 1
  br i1 %264, label %endBB39, label %bodyBB38bodyBB38cloneBB

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
  %265 = sub i32 %1, 1
  %266 = add i32 %1, 3
  %267 = add i32 %1, 4
  %268 = sub i32 %1, 3
  %269 = mul i32 %265, %266
  %270 = mul i32 %267, %268
  %271 = sub i32 %269, %270
  %272 = sub i32 %271, 9
  %273 = and i32 %272, 1
  %274 = icmp eq i32 %273, 1
  br i1 %274, label %bodyBB, label %endBB

bodyBB12bodyBB12cloneBB:                          ; preds = %bodyBB12, %22
  %src.addr.reload3bodyBB12cloneBB = load volatile i8**, i8*** %src.addr.reg2mem, align 8
  store i8* %src, i8** %src.addr.reload3bodyBB12cloneBB, align 8
  %src.addr.reload2bodyBB12cloneBB = load volatile i8**, i8*** %src.addr.reg2mem, align 8
  %275 = load i8*, i8** %src.addr.reload2bodyBB12cloneBB, align 8
  %callbodyBB12cloneBB = call i64 @strlen(i8* %275) #6
  %convbodyBB12cloneBB = trunc i64 %callbodyBB12cloneBB to i32
  %len.reload4bodyBB12cloneBB = load volatile i32*, i32** %len.reg2mem, align 8
  store i32 %convbodyBB12cloneBB, i32* %len.reload4bodyBB12cloneBB, align 4
  %276 = sub i32 %24, 1
  %277 = add i32 %24, 3
  %278 = add i32 %24, 4
  %279 = sub i32 %24, 3
  %280 = mul i32 %276, %277
  %281 = mul i32 %278, %279
  %282 = sub i32 %280, %281
  %283 = sub i32 %282, 9
  %284 = and i32 %283, 1
  %285 = icmp eq i32 %284, 1
  br i1 %285, label %bodyBB12, label %endBB13

bodyBB14bodyBB14cloneBB:                          ; preds = %bodyBB14, %46
  %i.reload11bodyBB14cloneBB = load volatile i32*, i32** %i.reg2mem, align 8
  store i32 0, i32* %i.reload11bodyBB14cloneBB, align 4
  %286 = mul i32 %48, 3
  %287 = sub i32 %48, 2
  %288 = mul i32 %286, %287
  %289 = mul i32 %48, %48
  %290 = mul i32 %289, 3
  %291 = mul i32 %48, 7
  %292 = sub i32 %288, %290
  %293 = add i32 %291, %292
  %294 = and i32 %293, 1
  %295 = icmp eq i32 %294, 1
  br i1 %295, label %bodyBB14, label %endBB15

bodyBB16bodyBB16cloneBB:                          ; preds = %bodyBB16, %for.cond
  %i.reload10bodyBB16cloneBB = load volatile i32*, i32** %i.reg2mem, align 8
  %296 = load i32, i32* %i.reload10bodyBB16cloneBB, align 4
  store i32 %296, i32* %.reg2mem, align 4
  %297 = add i32 %70, 1
  %298 = mul i32 %70, %297
  %299 = mul i32 %70, %70
  %300 = sub i32 %298, %299
  %301 = and i32 %300, 1
  %302 = icmp eq i32 %301, 1
  br i1 %302, label %bodyBB16, label %endBB17

bodyBB18bodyBB18cloneBB:                          ; preds = %bodyBB18, %88
  %len.reloadbodyBB18cloneBB = load volatile i32*, i32** %len.reg2mem, align 8
  %303 = load i32, i32* %len.reloadbodyBB18cloneBB, align 4
  store i32 %303, i32* %.reg2mem20, align 4
  %304 = sub i32 %90, 1
  %305 = add i32 %90, 3
  %306 = add i32 %90, 4
  %307 = sub i32 %90, 3
  %308 = mul i32 %304, %305
  %309 = mul i32 %306, %307
  %310 = sub i32 %308, %309
  %311 = sub i32 %310, 9
  %312 = and i32 %311, 1
  %313 = icmp eq i32 %312, 1
  br i1 %313, label %bodyBB18, label %endBB19

bodyBB22bodyBB22cloneBB:                          ; preds = %bodyBB22, %108
  %.reloadbodyBB22cloneBB = load volatile i32, i32* %.reg2mem, align 4
  %.reload21bodyBB22cloneBB = load volatile i32, i32* %.reg2mem20, align 4
  %cmpbodyBB22cloneBB = icmp slt i32 %.reloadbodyBB22cloneBB, %.reload21bodyBB22cloneBB
  store i1 %cmpbodyBB22cloneBB, i1* %cmp.reg2mem, align 1
  %314 = sub i32 %110, 1
  %315 = add i32 %110, 3
  %316 = add i32 %110, 4
  %317 = sub i32 %110, 3
  %318 = mul i32 %314, %315
  %319 = mul i32 %316, %317
  %320 = sub i32 %318, %319
  %321 = sub i32 %320, 9
  %322 = and i32 %321, 1
  %323 = icmp eq i32 %322, 1
  br i1 %323, label %bodyBB22, label %endBB23

bodyBB24bodyBB24cloneBB:                          ; preds = %bodyBB24, %for.body
  %src.addr.reloadbodyBB24cloneBB = load volatile i8**, i8*** %src.addr.reg2mem, align 8
  %324 = load i8*, i8** %src.addr.reloadbodyBB24cloneBB, align 8
  %i.reload9bodyBB24cloneBB = load volatile i32*, i32** %i.reg2mem, align 8
  %325 = load i32, i32* %i.reload9bodyBB24cloneBB, align 4
  %idxprombodyBB24cloneBB = sext i32 %325 to i64
  %arrayidxbodyBB24cloneBB = getelementptr inbounds i8, i8* %324, i64 %idxprombodyBB24cloneBB
  %326 = load i8, i8* %arrayidxbodyBB24cloneBB, align 1
  %conv1bodyBB24cloneBB = sext i8 %326 to i32
  store i32 %conv1bodyBB24cloneBB, i32* %conv1.reg2mem, align 4
  %i.reload8bodyBB24cloneBB = load volatile i32*, i32** %i.reg2mem, align 8
  %327 = load i32, i32* %i.reload8bodyBB24cloneBB, align 4
  %subbodyBB24cloneBB = sub nsw i32 32, %327
  store i32 %subbodyBB24cloneBB, i32* %sub.reg2mem, align 4
  %328 = sub i32 %132, 1
  %329 = add i32 %132, 3
  %330 = add i32 %132, 4
  %331 = sub i32 %132, 3
  %332 = mul i32 %328, %329
  %333 = mul i32 %330, %331
  %334 = sub i32 %332, %333
  %335 = sub i32 %334, 9
  %336 = and i32 %335, 1
  %337 = icmp eq i32 %336, 1
  br i1 %337, label %bodyBB24, label %endBB25

bodyBB26bodyBB26cloneBB:                          ; preds = %bodyBB26, %153
  %conv1.reloadbodyBB26cloneBB = load volatile i32, i32* %conv1.reg2mem, align 4
  %sub.reloadbodyBB26cloneBB = load volatile i32, i32* %sub.reg2mem, align 4
  %addbodyBB26cloneBB = add nsw i32 %conv1.reloadbodyBB26cloneBB, %sub.reloadbodyBB26cloneBB
  %i.reload7bodyBB26cloneBB = load volatile i32*, i32** %i.reg2mem, align 8
  %338 = load i32, i32* %i.reload7bodyBB26cloneBB, align 4
  %xorbodyBB26cloneBB = xor i32 %addbodyBB26cloneBB, %338
  %conv2bodyBB26cloneBB = trunc i32 %xorbodyBB26cloneBB to i8
  store i8 %conv2bodyBB26cloneBB, i8* %conv2.reg2mem, align 1
  %dest.addr.reloadbodyBB26cloneBB = load volatile i8**, i8*** %dest.addr.reg2mem, align 8
  %339 = load i8*, i8** %dest.addr.reloadbodyBB26cloneBB, align 8
  %i.reload6bodyBB26cloneBB = load volatile i32*, i32** %i.reg2mem, align 8
  %340 = load i32, i32* %i.reload6bodyBB26cloneBB, align 4
  %idxprom3bodyBB26cloneBB = sext i32 %340 to i64
  %arrayidx4bodyBB26cloneBB = getelementptr inbounds i8, i8* %339, i64 %idxprom3bodyBB26cloneBB
  store i8* %arrayidx4bodyBB26cloneBB, i8** %arrayidx4.reg2mem, align 8
  %341 = add i32 %155, 1
  %342 = mul i32 %155, %341
  %343 = mul i32 %155, %155
  %344 = sub i32 %342, %343
  %345 = and i32 %344, 1
  %346 = icmp eq i32 %345, 1
  br i1 %346, label %bodyBB26, label %endBB27

bodyBB28bodyBB28cloneBB:                          ; preds = %bodyBB28, %175
  %conv2.reloadbodyBB28cloneBB = load volatile i8, i8* %conv2.reg2mem, align 1
  %arrayidx4.reloadbodyBB28cloneBB = load volatile i8*, i8** %arrayidx4.reg2mem, align 8
  store i8 %conv2.reloadbodyBB28cloneBB, i8* %arrayidx4.reloadbodyBB28cloneBB, align 1
  %347 = mul i32 %177, 3
  %348 = sub i32 %177, 2
  %349 = mul i32 %347, %348
  %350 = mul i32 %177, %177
  %351 = mul i32 %350, 3
  %352 = mul i32 %177, 7
  %353 = sub i32 %349, %351
  %354 = add i32 %352, %353
  %355 = and i32 %354, 1
  %356 = icmp eq i32 %355, 1
  br i1 %356, label %bodyBB28, label %endBB29

bodyBB30bodyBB30cloneBB:                          ; preds = %bodyBB30, %for.inc
  %i.reload5bodyBB30cloneBB = load volatile i32*, i32** %i.reg2mem, align 8
  %357 = load i32, i32* %i.reload5bodyBB30cloneBB, align 4
  store i32 %357, i32* %.reg2mem32, align 4
  %358 = mul i32 %195, 3
  %359 = sub i32 %195, 2
  %360 = mul i32 %358, %359
  %361 = mul i32 %195, %195
  %362 = mul i32 %361, 3
  %363 = mul i32 %195, 7
  %364 = sub i32 %360, %362
  %365 = add i32 %363, %364
  %366 = and i32 %365, 1
  %367 = icmp eq i32 %366, 1
  br i1 %367, label %bodyBB30, label %endBB31

bodyBB34bodyBB34cloneBB:                          ; preds = %bodyBB34, %209
  %.reload33bodyBB34cloneBB = load volatile i32, i32* %.reg2mem32, align 4
  %incbodyBB34cloneBB = add nsw i32 %.reload33bodyBB34cloneBB, 1
  store i32 %incbodyBB34cloneBB, i32* %inc.reg2mem, align 4
  %368 = mul i32 %211, 3
  %369 = sub i32 %211, 2
  %370 = mul i32 %368, %369
  %371 = mul i32 %211, %211
  %372 = mul i32 %371, 3
  %373 = mul i32 %211, 7
  %374 = sub i32 %370, %372
  %375 = add i32 %373, %374
  %376 = and i32 %375, 1
  %377 = icmp eq i32 %376, 1
  br i1 %377, label %bodyBB34, label %endBB35

bodyBB36bodyBB36cloneBB:                          ; preds = %bodyBB36, %232
  %i.reloadbodyBB36cloneBB = load volatile i32*, i32** %i.reg2mem, align 8
  %inc.reloadbodyBB36cloneBB = load volatile i32, i32* %inc.reg2mem, align 4
  store i32 %inc.reloadbodyBB36cloneBB, i32* %i.reloadbodyBB36cloneBB, align 4
  %378 = sub i32 %234, 1
  %379 = add i32 %234, 3
  %380 = add i32 %234, 4
  %381 = sub i32 %234, 3
  %382 = mul i32 %378, %379
  %383 = mul i32 %380, %381
  %384 = sub i32 %382, %383
  %385 = sub i32 %384, 9
  %386 = and i32 %385, 1
  %387 = icmp eq i32 %386, 1
  br i1 %387, label %bodyBB36, label %endBB37

bodyBB38bodyBB38cloneBB:                          ; preds = %bodyBB38, %for.end
  %388 = add i32 %252, 1
  %389 = mul i32 %252, %388
  %390 = mul i32 %252, %252
  %391 = sub i32 %389, %390
  %392 = and i32 %391, 1
  %393 = icmp eq i32 %392, 1
  br i1 %393, label %bodyBB38, label %endBB39
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
  %2 = mul i32 %1, 3
  %3 = sub i32 %1, 2
  %4 = mul i32 %2, %3
  %5 = mul i32 %1, %1
  %6 = mul i32 %5, 3
  %7 = mul i32 %1, 7
  %8 = sub i32 %4, %6
  %9 = add i32 %7, %8
  %10 = and i32 %9, 1
  %11 = icmp eq i32 %10, 1
  br i1 %11, label %bodyBB, label %bodyBBbodyBBcloneBB

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
  %12 = add i32 %1, 1
  %13 = mul i32 %1, %12
  %14 = mul i32 %1, %1
  %15 = sub i32 %13, %14
  %16 = and i32 %15, 1
  %17 = icmp eq i32 %16, 1
  br i1 %17, label %endBB, label %bodyBBbodyBBcloneBB

endBB:                                            ; preds = %bodyBBbodyBBcloneBB, %bodyBB
  br label %18

18:                                               ; preds = %endBB
  %19 = call { i32, i32 } @llvm.x86.rdrand.32()
  %20 = extractvalue { i32, i32 } %19, 0
  %21 = sub i32 %20, 1
  %22 = add i32 %20, 3
  %23 = add i32 %20, 4
  %24 = sub i32 %20, 3
  %25 = mul i32 %21, %22
  %26 = mul i32 %23, %24
  %27 = sub i32 %25, %26
  %28 = sub i32 %27, 9
  %29 = and i32 %28, 1
  %30 = icmp eq i32 %29, 1
  br i1 %30, label %bodyBB8, label %bodyBB8bodyBB8cloneBB

bodyBB8:                                          ; preds = %bodyBB8bodyBB8cloneBB, %18
  %retval.reload2 = load volatile i32*, i32** %retval.reg2mem, align 8
  store i32 0, i32* %retval.reload2, align 4
  %argc.addr.reload3 = load volatile i32*, i32** %argc.addr.reg2mem, align 8
  store i32 %argc, i32* %argc.addr.reload3, align 4
  %argv.addr.reload4 = load volatile i8***, i8**** %argv.addr.reg2mem, align 8
  store i8** %argv, i8*** %argv.addr.reload4, align 8
  %call = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([26 x i8], [26 x i8]* @.str, i64 0, i64 0))
  %argc.addr.reload = load volatile i32*, i32** %argc.addr.reg2mem, align 8
  %31 = load i32, i32* %argc.addr.reload, align 4
  store i32 %31, i32* %.reg2mem, align 4
  %32 = mul i32 %20, 3
  %33 = sub i32 %20, 2
  %34 = mul i32 %32, %33
  %35 = mul i32 %20, %20
  %36 = mul i32 %35, 3
  %37 = mul i32 %20, 7
  %38 = sub i32 %34, %36
  %39 = add i32 %37, %38
  %40 = and i32 %39, 1
  %41 = icmp eq i32 %40, 1
  br i1 %41, label %endBB9, label %bodyBB8bodyBB8cloneBB

endBB9:                                           ; preds = %bodyBB8bodyBB8cloneBB, %bodyBB8
  br label %42

42:                                               ; preds = %endBB9
  %43 = call { i32, i32 } @llvm.x86.rdrand.32()
  %44 = extractvalue { i32, i32 } %43, 0
  %45 = sub i32 %44, 1
  %46 = add i32 %44, 3
  %47 = add i32 %44, 4
  %48 = sub i32 %44, 3
  %49 = mul i32 %45, %46
  %50 = mul i32 %47, %48
  %51 = sub i32 %49, %50
  %52 = sub i32 %51, 9
  %53 = and i32 %52, 1
  %54 = icmp eq i32 %53, 1
  br i1 %54, label %bodyBB10, label %bodyBB10bodyBB10cloneBB

bodyBB10:                                         ; preds = %bodyBB10bodyBB10cloneBB, %42
  %.reload = load volatile i32, i32* %.reg2mem, align 4
  %cmp = icmp sle i32 %.reload, 1
  store i1 %cmp, i1* %cmp.reg2mem, align 1
  %55 = mul i32 %44, 3
  %56 = sub i32 %44, 2
  %57 = mul i32 %55, %56
  %58 = mul i32 %44, %44
  %59 = mul i32 %58, 3
  %60 = mul i32 %44, 7
  %61 = sub i32 %57, %59
  %62 = add i32 %60, %61
  %63 = and i32 %62, 1
  %64 = icmp eq i32 %63, 1
  br i1 %64, label %endBB11, label %bodyBB10bodyBB10cloneBB

endBB11:                                          ; preds = %bodyBB10bodyBB10cloneBB, %bodyBB10
  %cmp.reload = load volatile i1, i1* %cmp.reg2mem, align 1
  br i1 %cmp.reload, label %if.then, label %if.end

if.then:                                          ; preds = %endBB11
  %65 = call { i32, i32 } @llvm.x86.rdrand.32()
  %66 = extractvalue { i32, i32 } %65, 0
  %67 = sub i32 %66, 1
  %68 = add i32 %66, 3
  %69 = add i32 %66, 4
  %70 = sub i32 %66, 3
  %71 = mul i32 %67, %68
  %72 = mul i32 %69, %70
  %73 = sub i32 %71, %72
  %74 = sub i32 %73, 9
  %75 = and i32 %74, 1
  %76 = icmp eq i32 %75, 1
  br i1 %76, label %bodyBB12, label %bodyBB12bodyBB12cloneBB

bodyBB12:                                         ; preds = %bodyBB12bodyBB12cloneBB, %if.then
  %77 = add i32 %66, 1
  %78 = mul i32 %66, %77
  %79 = mul i32 %66, %66
  %80 = sub i32 %78, %79
  %81 = and i32 %80, 1
  %82 = icmp eq i32 %81, 1
  br i1 %82, label %endBB13, label %bodyBB12bodyBB12cloneBB

endBB13:                                          ; preds = %bodyBB12bodyBB12cloneBB, %bodyBB12
  br label %83

83:                                               ; preds = %endBB13
  %84 = call { i32, i32 } @llvm.x86.rdrand.32()
  %85 = extractvalue { i32, i32 } %84, 0
  %86 = sub i32 %85, 1
  %87 = add i32 %85, 3
  %88 = add i32 %85, 4
  %89 = sub i32 %85, 3
  %90 = mul i32 %86, %87
  %91 = mul i32 %88, %89
  %92 = sub i32 %90, %91
  %93 = sub i32 %92, 9
  %94 = and i32 %93, 1
  %95 = icmp eq i32 %94, 1
  br i1 %95, label %bodyBB14, label %bodyBB14bodyBB14cloneBB

bodyBB14:                                         ; preds = %bodyBB14bodyBB14cloneBB, %83
  %96 = mul i32 %85, 3
  %97 = sub i32 %85, 2
  %98 = mul i32 %96, %97
  %99 = mul i32 %85, %85
  %100 = mul i32 %99, 3
  %101 = mul i32 %85, 7
  %102 = sub i32 %98, %100
  %103 = add i32 %101, %102
  %104 = and i32 %103, 1
  %105 = icmp eq i32 %104, 1
  br i1 %105, label %endBB15, label %bodyBB14bodyBB14cloneBB

endBB15:                                          ; preds = %bodyBB14bodyBB14cloneBB, %bodyBB14
  br label %106

106:                                              ; preds = %endBB15
  %107 = call { i32, i32 } @llvm.x86.rdrand.32()
  %108 = extractvalue { i32, i32 } %107, 0
  %109 = sub i32 %108, 1
  %110 = add i32 %108, 3
  %111 = add i32 %108, 4
  %112 = sub i32 %108, 3
  %113 = mul i32 %109, %110
  %114 = mul i32 %111, %112
  %115 = sub i32 %113, %114
  %116 = sub i32 %115, 9
  %117 = and i32 %116, 1
  %118 = icmp eq i32 %117, 1
  br i1 %118, label %bodyBB16, label %bodyBB16bodyBB16cloneBB

bodyBB16:                                         ; preds = %bodyBB16bodyBB16cloneBB, %106
  %call1 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([33 x i8], [33 x i8]* @.str.1, i64 0, i64 0))
  %retval.reload1 = load volatile i32*, i32** %retval.reg2mem, align 8
  store i32 0, i32* %retval.reload1, align 4
  %119 = sub i32 %108, 1
  %120 = add i32 %108, 3
  %121 = add i32 %108, 4
  %122 = sub i32 %108, 3
  %123 = mul i32 %119, %120
  %124 = mul i32 %121, %122
  %125 = sub i32 %123, %124
  %126 = sub i32 %125, 9
  %127 = and i32 %126, 1
  %128 = icmp eq i32 %127, 1
  br i1 %128, label %endBB17, label %bodyBB16bodyBB16cloneBB

endBB17:                                          ; preds = %bodyBB16bodyBB16cloneBB, %bodyBB16
  br label %if.end11

if.end:                                           ; preds = %endBB11
  %129 = call { i32, i32 } @llvm.x86.rdrand.32()
  %130 = extractvalue { i32, i32 } %129, 0
  %131 = mul i32 %130, 3
  %132 = sub i32 %130, 2
  %133 = mul i32 %131, %132
  %134 = mul i32 %130, %130
  %135 = mul i32 %134, 3
  %136 = mul i32 %130, 7
  %137 = sub i32 %133, %135
  %138 = add i32 %136, %137
  %139 = and i32 %138, 1
  %140 = icmp eq i32 %139, 1
  br i1 %140, label %bodyBB18, label %bodyBB18bodyBB18cloneBB

bodyBB18:                                         ; preds = %bodyBB18bodyBB18cloneBB, %if.end
  %argv.addr.reload = load volatile i8***, i8**** %argv.addr.reg2mem, align 8
  %141 = load i8**, i8*** %argv.addr.reload, align 8
  %arrayidx = getelementptr inbounds i8*, i8** %141, i64 1
  %142 = load i8*, i8** %arrayidx, align 8
  store i8* %142, i8** @input, align 8
  %143 = load i8*, i8** @input, align 8
  %call2 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([18 x i8], [18 x i8]* @.str.2, i64 0, i64 0), i8* %143)
  %144 = mul i32 %130, 3
  %145 = sub i32 %130, 2
  %146 = mul i32 %144, %145
  %147 = mul i32 %130, %130
  %148 = mul i32 %147, 3
  %149 = mul i32 %130, 7
  %150 = sub i32 %146, %148
  %151 = add i32 %149, %150
  %152 = and i32 %151, 1
  %153 = icmp eq i32 %152, 1
  br i1 %153, label %endBB19, label %bodyBB18bodyBB18cloneBB

endBB19:                                          ; preds = %bodyBB18bodyBB18cloneBB, %bodyBB18
  br label %154

154:                                              ; preds = %endBB19
  %155 = call { i32, i32 } @llvm.x86.rdrand.32()
  %156 = extractvalue { i32, i32 } %155, 0
  %157 = sub i32 %156, 1
  %158 = add i32 %156, 3
  %159 = add i32 %156, 4
  %160 = sub i32 %156, 3
  %161 = mul i32 %157, %158
  %162 = mul i32 %159, %160
  %163 = sub i32 %161, %162
  %164 = sub i32 %163, 9
  %165 = and i32 %164, 1
  %166 = icmp eq i32 %165, 1
  br i1 %166, label %bodyBB20, label %bodyBB20bodyBB20cloneBB

bodyBB20:                                         ; preds = %bodyBB20bodyBB20cloneBB, %154
  %dest.reload6 = load volatile [100 x i8]*, [100 x i8]** %dest.reg2mem, align 8
  %167 = bitcast [100 x i8]* %dest.reload6 to i8*
  call void @llvm.memset.p0i8.i64(i8* align 16 %167, i8 0, i64 100, i1 false)
  %dest.reload5 = load volatile [100 x i8]*, [100 x i8]** %dest.reg2mem, align 8
  %arraydecay = getelementptr inbounds [100 x i8], [100 x i8]* %dest.reload5, i64 0, i64 0
  %168 = load i8*, i8** @input, align 8
  call void @_Z7encryptPhPc(i8* %arraydecay, i8* %168)
  %169 = load i8*, i8** @input, align 8
  store i8* %169, i8** %.reg2mem22, align 8
  %170 = sub i32 %156, 1
  %171 = add i32 %156, 3
  %172 = add i32 %156, 4
  %173 = sub i32 %156, 3
  %174 = mul i32 %170, %171
  %175 = mul i32 %172, %173
  %176 = sub i32 %174, %175
  %177 = sub i32 %176, 9
  %178 = and i32 %177, 1
  %179 = icmp eq i32 %178, 1
  br i1 %179, label %endBB21, label %bodyBB20bodyBB20cloneBB

endBB21:                                          ; preds = %bodyBB20bodyBB20cloneBB, %bodyBB20
  br label %180

180:                                              ; preds = %endBB21
  %181 = call { i32, i32 } @llvm.x86.rdrand.32()
  %182 = extractvalue { i32, i32 } %181, 0
  %183 = add i32 %182, 1
  %184 = mul i32 %182, %183
  %185 = mul i32 %182, %182
  %186 = sub i32 %184, %185
  %187 = and i32 %186, 1
  %188 = icmp eq i32 %187, 1
  br i1 %188, label %bodyBB24, label %bodyBB24bodyBB24cloneBB

bodyBB24:                                         ; preds = %bodyBB24bodyBB24cloneBB, %180
  %.reload23 = load volatile i8*, i8** %.reg2mem22, align 8
  %call3 = call i64 @strlen(i8* %.reload23) #6
  %cmp4 = icmp eq i64 %call3, 22
  store i1 %cmp4, i1* %cmp4.reg2mem, align 1
  %189 = sub i32 %182, 1
  %190 = add i32 %182, 3
  %191 = add i32 %182, 4
  %192 = sub i32 %182, 3
  %193 = mul i32 %189, %190
  %194 = mul i32 %191, %192
  %195 = sub i32 %193, %194
  %196 = sub i32 %195, 9
  %197 = and i32 %196, 1
  %198 = icmp eq i32 %197, 1
  br i1 %198, label %endBB25, label %bodyBB24bodyBB24cloneBB

endBB25:                                          ; preds = %bodyBB24bodyBB24cloneBB, %bodyBB24
  %cmp4.reload = load volatile i1, i1* %cmp4.reg2mem, align 1
  br i1 %cmp4.reload, label %land.rhs, label %land.end

land.rhs:                                         ; preds = %endBB25
  %199 = call { i32, i32 } @llvm.x86.rdrand.32()
  %200 = extractvalue { i32, i32 } %199, 0
  %201 = add i32 %200, 1
  %202 = mul i32 %200, %201
  %203 = mul i32 %200, %200
  %204 = sub i32 %202, %203
  %205 = and i32 %204, 1
  %206 = icmp eq i32 %205, 1
  br i1 %206, label %bodyBB26, label %bodyBB26bodyBB26cloneBB

bodyBB26:                                         ; preds = %bodyBB26bodyBB26cloneBB, %land.rhs
  %dest.reload = load volatile [100 x i8]*, [100 x i8]** %dest.reg2mem, align 8
  %arraydecay5 = getelementptr inbounds [100 x i8], [100 x i8]* %dest.reload, i64 0, i64 0
  store i8* %arraydecay5, i8** %arraydecay5.reg2mem, align 8
  %207 = sub i32 %200, 1
  %208 = add i32 %200, 3
  %209 = add i32 %200, 4
  %210 = sub i32 %200, 3
  %211 = mul i32 %207, %208
  %212 = mul i32 %209, %210
  %213 = sub i32 %211, %212
  %214 = sub i32 %213, 9
  %215 = and i32 %214, 1
  %216 = icmp eq i32 %215, 1
  br i1 %216, label %endBB27, label %bodyBB26bodyBB26cloneBB

endBB27:                                          ; preds = %bodyBB26bodyBB26cloneBB, %bodyBB26
  br label %217

217:                                              ; preds = %endBB27
  %218 = call { i32, i32 } @llvm.x86.rdrand.32()
  %219 = extractvalue { i32, i32 } %218, 0
  %220 = mul i32 %219, 3
  %221 = sub i32 %219, 2
  %222 = mul i32 %220, %221
  %223 = mul i32 %219, %219
  %224 = mul i32 %223, 3
  %225 = mul i32 %219, 7
  %226 = sub i32 %222, %224
  %227 = add i32 %225, %226
  %228 = and i32 %227, 1
  %229 = icmp eq i32 %228, 1
  br i1 %229, label %bodyBB28, label %bodyBB28bodyBB28cloneBB

bodyBB28:                                         ; preds = %bodyBB28bodyBB28cloneBB, %217
  %arraydecay5.reload = load volatile i8*, i8** %arraydecay5.reg2mem, align 8
  %call6 = call i32 @memcmp(i8* %arraydecay5.reload, i8* getelementptr inbounds ([100 x i8], [100 x i8]* bitcast (<{ [22 x i8], [78 x i8] }>* @enc to [100 x i8]*), i64 0, i64 0), i64 22) #6
  store i32 %call6, i32* %call6.reg2mem, align 4
  %230 = sub i32 %219, 1
  %231 = add i32 %219, 3
  %232 = add i32 %219, 4
  %233 = sub i32 %219, 3
  %234 = mul i32 %230, %231
  %235 = mul i32 %232, %233
  %236 = sub i32 %234, %235
  %237 = sub i32 %236, 9
  %238 = and i32 %237, 1
  %239 = icmp eq i32 %238, 1
  br i1 %239, label %endBB29, label %bodyBB28bodyBB28cloneBB

endBB29:                                          ; preds = %bodyBB28bodyBB28cloneBB, %bodyBB28
  br label %240

240:                                              ; preds = %endBB29
  %241 = call { i32, i32 } @llvm.x86.rdrand.32()
  %242 = extractvalue { i32, i32 } %241, 0
  %243 = add i32 %242, 1
  %244 = mul i32 %242, %243
  %245 = mul i32 %242, %242
  %246 = sub i32 %244, %245
  %247 = and i32 %246, 1
  %248 = icmp eq i32 %247, 1
  br i1 %248, label %bodyBB30, label %bodyBB30bodyBB30cloneBB

bodyBB30:                                         ; preds = %bodyBB30bodyBB30cloneBB, %240
  %call6.reload = load volatile i32, i32* %call6.reg2mem, align 4
  %tobool = icmp ne i32 %call6.reload, 0
  %lnot = xor i1 %tobool, true
  store i1 %lnot, i1* %lnot.reg2mem, align 1
  %249 = mul i32 %242, 3
  %250 = sub i32 %242, 2
  %251 = mul i32 %249, %250
  %252 = mul i32 %242, %242
  %253 = mul i32 %252, 3
  %254 = mul i32 %242, 7
  %255 = sub i32 %251, %253
  %256 = add i32 %254, %255
  %257 = and i32 %256, 1
  %258 = icmp eq i32 %257, 1
  br i1 %258, label %endBB31, label %bodyBB30bodyBB30cloneBB

endBB31:                                          ; preds = %bodyBB30bodyBB30cloneBB, %bodyBB30
  %lnot.reload = load volatile i1, i1* %lnot.reg2mem, align 1
  br label %land.end

land.end:                                         ; preds = %endBB31, %endBB25
  %259 = phi i1 [ false, %endBB25 ], [ %lnot.reload, %endBB31 ]
  %260 = call { i32, i32 } @llvm.x86.rdrand.32()
  %261 = extractvalue { i32, i32 } %260, 0
  %262 = add i32 %261, 1
  %263 = mul i32 %261, %262
  %264 = mul i32 %261, %261
  %265 = sub i32 %263, %264
  %266 = and i32 %265, 1
  %267 = icmp eq i32 %266, 1
  br i1 %267, label %bodyBB32, label %bodyBB32bodyBB32cloneBB

bodyBB32:                                         ; preds = %bodyBB32bodyBB32cloneBB, %land.end
  %frombool = zext i1 %259 to i8
  %result.reload7 = load volatile i8*, i8** %result.reg2mem, align 8
  store i8 %frombool, i8* %result.reload7, align 1
  %result.reload = load volatile i8*, i8** %result.reg2mem, align 8
  %268 = load i8, i8* %result.reload, align 1
  %tobool7 = trunc i8 %268 to i1
  store i1 %tobool7, i1* %tobool7.reg2mem, align 1
  %269 = sub i32 %261, 1
  %270 = add i32 %261, 3
  %271 = add i32 %261, 4
  %272 = sub i32 %261, 3
  %273 = mul i32 %269, %270
  %274 = mul i32 %271, %272
  %275 = sub i32 %273, %274
  %276 = sub i32 %275, 9
  %277 = and i32 %276, 1
  %278 = icmp eq i32 %277, 1
  br i1 %278, label %endBB33, label %bodyBB32bodyBB32cloneBB

endBB33:                                          ; preds = %bodyBB32bodyBB32cloneBB, %bodyBB32
  %tobool7.reload = load volatile i1, i1* %tobool7.reg2mem, align 1
  br i1 %tobool7.reload, label %if.then8, label %if.else

if.then8:                                         ; preds = %endBB33
  %279 = call { i32, i32 } @llvm.x86.rdrand.32()
  %280 = extractvalue { i32, i32 } %279, 0
  %281 = sub i32 %280, 1
  %282 = add i32 %280, 3
  %283 = add i32 %280, 4
  %284 = sub i32 %280, 3
  %285 = mul i32 %281, %282
  %286 = mul i32 %283, %284
  %287 = sub i32 %285, %286
  %288 = sub i32 %287, 9
  %289 = and i32 %288, 1
  %290 = icmp eq i32 %289, 1
  br i1 %290, label %bodyBB34, label %bodyBB34bodyBB34cloneBB

bodyBB34:                                         ; preds = %bodyBB34bodyBB34cloneBB, %if.then8
  %291 = mul i32 %280, 3
  %292 = sub i32 %280, 2
  %293 = mul i32 %291, %292
  %294 = mul i32 %280, %280
  %295 = mul i32 %294, 3
  %296 = mul i32 %280, 7
  %297 = sub i32 %293, %295
  %298 = add i32 %296, %297
  %299 = and i32 %298, 1
  %300 = icmp eq i32 %299, 1
  br i1 %300, label %endBB35, label %bodyBB34bodyBB34cloneBB

endBB35:                                          ; preds = %bodyBB34bodyBB34cloneBB, %bodyBB34
  br label %301

301:                                              ; preds = %endBB35
  %302 = call { i32, i32 } @llvm.x86.rdrand.32()
  %303 = extractvalue { i32, i32 } %302, 0
  %304 = add i32 %303, 1
  %305 = mul i32 %303, %304
  %306 = mul i32 %303, %303
  %307 = sub i32 %305, %306
  %308 = and i32 %307, 1
  %309 = icmp eq i32 %308, 1
  br i1 %309, label %bodyBB36, label %bodyBB36bodyBB36cloneBB

bodyBB36:                                         ; preds = %bodyBB36bodyBB36cloneBB, %301
  %310 = mul i32 %303, 3
  %311 = sub i32 %303, 2
  %312 = mul i32 %310, %311
  %313 = mul i32 %303, %303
  %314 = mul i32 %313, 3
  %315 = mul i32 %303, 7
  %316 = sub i32 %312, %314
  %317 = add i32 %315, %316
  %318 = and i32 %317, 1
  %319 = icmp eq i32 %318, 1
  br i1 %319, label %endBB37, label %bodyBB36bodyBB36cloneBB

endBB37:                                          ; preds = %bodyBB36bodyBB36cloneBB, %bodyBB36
  br label %320

320:                                              ; preds = %endBB37
  %321 = call { i32, i32 } @llvm.x86.rdrand.32()
  %322 = extractvalue { i32, i32 } %321, 0
  %323 = sub i32 %322, 1
  %324 = add i32 %322, 3
  %325 = add i32 %322, 4
  %326 = sub i32 %322, 3
  %327 = mul i32 %323, %324
  %328 = mul i32 %325, %326
  %329 = sub i32 %327, %328
  %330 = sub i32 %329, 9
  %331 = and i32 %330, 1
  %332 = icmp eq i32 %331, 1
  br i1 %332, label %bodyBB38, label %bodyBB38bodyBB38cloneBB

bodyBB38:                                         ; preds = %bodyBB38bodyBB38cloneBB, %320
  %call9 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([18 x i8], [18 x i8]* @.str.3, i64 0, i64 0))
  %333 = add i32 %322, 1
  %334 = mul i32 %322, %333
  %335 = mul i32 %322, %322
  %336 = sub i32 %334, %335
  %337 = and i32 %336, 1
  %338 = icmp eq i32 %337, 1
  br i1 %338, label %endBB39, label %bodyBB38bodyBB38cloneBB

endBB39:                                          ; preds = %bodyBB38bodyBB38cloneBB, %bodyBB38
  br label %if.end11

if.else:                                          ; preds = %endBB33
  %339 = call { i32, i32 } @llvm.x86.rdrand.32()
  %340 = extractvalue { i32, i32 } %339, 0
  %341 = mul i32 %340, 3
  %342 = sub i32 %340, 2
  %343 = mul i32 %341, %342
  %344 = mul i32 %340, %340
  %345 = mul i32 %344, 3
  %346 = mul i32 %340, 7
  %347 = sub i32 %343, %345
  %348 = add i32 %346, %347
  %349 = and i32 %348, 1
  %350 = icmp eq i32 %349, 1
  br i1 %350, label %bodyBB40, label %bodyBB40bodyBB40cloneBB

bodyBB40:                                         ; preds = %bodyBB40bodyBB40cloneBB, %if.else
  %351 = mul i32 %340, 3
  %352 = sub i32 %340, 2
  %353 = mul i32 %351, %352
  %354 = mul i32 %340, %340
  %355 = mul i32 %354, 3
  %356 = mul i32 %340, 7
  %357 = sub i32 %353, %355
  %358 = add i32 %356, %357
  %359 = and i32 %358, 1
  %360 = icmp eq i32 %359, 1
  br i1 %360, label %endBB41, label %bodyBB40bodyBB40cloneBB

endBB41:                                          ; preds = %bodyBB40bodyBB40cloneBB, %bodyBB40
  br label %361

361:                                              ; preds = %endBB41
  %362 = call { i32, i32 } @llvm.x86.rdrand.32()
  %363 = extractvalue { i32, i32 } %362, 0
  %364 = sub i32 %363, 1
  %365 = add i32 %363, 3
  %366 = add i32 %363, 4
  %367 = sub i32 %363, 3
  %368 = mul i32 %364, %365
  %369 = mul i32 %366, %367
  %370 = sub i32 %368, %369
  %371 = sub i32 %370, 9
  %372 = and i32 %371, 1
  %373 = icmp eq i32 %372, 1
  br i1 %373, label %bodyBB42, label %bodyBB42bodyBB42cloneBB

bodyBB42:                                         ; preds = %bodyBB42bodyBB42cloneBB, %361
  %374 = sub i32 %363, 1
  %375 = add i32 %363, 3
  %376 = add i32 %363, 4
  %377 = sub i32 %363, 3
  %378 = mul i32 %374, %375
  %379 = mul i32 %376, %377
  %380 = sub i32 %378, %379
  %381 = sub i32 %380, 9
  %382 = and i32 %381, 1
  %383 = icmp eq i32 %382, 1
  br i1 %383, label %endBB43, label %bodyBB42bodyBB42cloneBB

endBB43:                                          ; preds = %bodyBB42bodyBB42cloneBB, %bodyBB42
  br label %384

384:                                              ; preds = %endBB43
  %385 = call { i32, i32 } @llvm.x86.rdrand.32()
  %386 = extractvalue { i32, i32 } %385, 0
  %387 = sub i32 %386, 1
  %388 = add i32 %386, 3
  %389 = add i32 %386, 4
  %390 = sub i32 %386, 3
  %391 = mul i32 %387, %388
  %392 = mul i32 %389, %390
  %393 = sub i32 %391, %392
  %394 = sub i32 %393, 9
  %395 = and i32 %394, 1
  %396 = icmp eq i32 %395, 1
  br i1 %396, label %bodyBB44, label %bodyBB44bodyBB44cloneBB

bodyBB44:                                         ; preds = %bodyBB44bodyBB44cloneBB, %384
  %call10 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([18 x i8], [18 x i8]* @.str.4, i64 0, i64 0))
  %397 = add i32 %386, 1
  %398 = mul i32 %386, %397
  %399 = mul i32 %386, %386
  %400 = sub i32 %398, %399
  %401 = and i32 %400, 1
  %402 = icmp eq i32 %401, 1
  br i1 %402, label %endBB45, label %bodyBB44bodyBB44cloneBB

endBB45:                                          ; preds = %bodyBB44bodyBB44cloneBB, %bodyBB44
  br label %if.end11

if.end11:                                         ; preds = %endBB45, %endBB39, %endBB17
  %403 = call { i32, i32 } @llvm.x86.rdrand.32()
  %404 = extractvalue { i32, i32 } %403, 0
  %405 = sub i32 %404, 1
  %406 = add i32 %404, 3
  %407 = add i32 %404, 4
  %408 = sub i32 %404, 3
  %409 = mul i32 %405, %406
  %410 = mul i32 %407, %408
  %411 = sub i32 %409, %410
  %412 = sub i32 %411, 9
  %413 = and i32 %412, 1
  %414 = icmp eq i32 %413, 1
  br i1 %414, label %bodyBB46, label %bodyBB46bodyBB46cloneBB

bodyBB46:                                         ; preds = %bodyBB46bodyBB46cloneBB, %if.end11
  %415 = mul i32 %404, 3
  %416 = sub i32 %404, 2
  %417 = mul i32 %415, %416
  %418 = mul i32 %404, %404
  %419 = mul i32 %418, 3
  %420 = mul i32 %404, 7
  %421 = sub i32 %417, %419
  %422 = add i32 %420, %421
  %423 = and i32 %422, 1
  %424 = icmp eq i32 %423, 1
  br i1 %424, label %endBB47, label %bodyBB46bodyBB46cloneBB

endBB47:                                          ; preds = %bodyBB46bodyBB46cloneBB, %bodyBB46
  br label %425

425:                                              ; preds = %endBB47
  %426 = call { i32, i32 } @llvm.x86.rdrand.32()
  %427 = extractvalue { i32, i32 } %426, 0
  %428 = sub i32 %427, 1
  %429 = add i32 %427, 3
  %430 = add i32 %427, 4
  %431 = sub i32 %427, 3
  %432 = mul i32 %428, %429
  %433 = mul i32 %430, %431
  %434 = sub i32 %432, %433
  %435 = sub i32 %434, 9
  %436 = and i32 %435, 1
  %437 = icmp eq i32 %436, 1
  br i1 %437, label %bodyBB48, label %bodyBB48bodyBB48cloneBB

bodyBB48:                                         ; preds = %bodyBB48bodyBB48cloneBB, %425
  %438 = add i32 %427, 1
  %439 = mul i32 %427, %438
  %440 = mul i32 %427, %427
  %441 = sub i32 %439, %440
  %442 = and i32 %441, 1
  %443 = icmp eq i32 %442, 1
  br i1 %443, label %endBB49, label %bodyBB48bodyBB48cloneBB

endBB49:                                          ; preds = %bodyBB48bodyBB48cloneBB, %bodyBB48
  br label %444

444:                                              ; preds = %endBB49
  %445 = call { i32, i32 } @llvm.x86.rdrand.32()
  %446 = extractvalue { i32, i32 } %445, 0
  %447 = mul i32 %446, 3
  %448 = sub i32 %446, 2
  %449 = mul i32 %447, %448
  %450 = mul i32 %446, %446
  %451 = mul i32 %450, 3
  %452 = mul i32 %446, 7
  %453 = sub i32 %449, %451
  %454 = add i32 %452, %453
  %455 = and i32 %454, 1
  %456 = icmp eq i32 %455, 1
  br i1 %456, label %bodyBB50, label %bodyBB50bodyBB50cloneBB

bodyBB50:                                         ; preds = %bodyBB50bodyBB50cloneBB, %444
  %retval.reload = load volatile i32*, i32** %retval.reg2mem, align 8
  %457 = load i32, i32* %retval.reload, align 4
  store i32 %457, i32* %.reg2mem52, align 4
  %458 = mul i32 %446, 3
  %459 = sub i32 %446, 2
  %460 = mul i32 %458, %459
  %461 = mul i32 %446, %446
  %462 = mul i32 %461, 3
  %463 = mul i32 %446, 7
  %464 = sub i32 %460, %462
  %465 = add i32 %463, %464
  %466 = and i32 %465, 1
  %467 = icmp eq i32 %466, 1
  br i1 %467, label %endBB51, label %bodyBB50bodyBB50cloneBB

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
  %468 = mul i32 %1, 3
  %469 = sub i32 %1, 2
  %470 = mul i32 %468, %469
  %471 = mul i32 %1, %1
  %472 = mul i32 %471, 3
  %473 = mul i32 %1, 7
  %474 = sub i32 %470, %472
  %475 = add i32 %473, %474
  %476 = and i32 %475, 1
  %477 = icmp eq i32 %476, 1
  br i1 %477, label %bodyBB, label %endBB

bodyBB8bodyBB8cloneBB:                            ; preds = %bodyBB8, %18
  %retval.reload2bodyBB8cloneBB = load volatile i32*, i32** %retval.reg2mem, align 8
  store i32 0, i32* %retval.reload2bodyBB8cloneBB, align 4
  %argc.addr.reload3bodyBB8cloneBB = load volatile i32*, i32** %argc.addr.reg2mem, align 8
  store i32 %argc, i32* %argc.addr.reload3bodyBB8cloneBB, align 4
  %argv.addr.reload4bodyBB8cloneBB = load volatile i8***, i8**** %argv.addr.reg2mem, align 8
  store i8** %argv, i8*** %argv.addr.reload4bodyBB8cloneBB, align 8
  %callbodyBB8cloneBB = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([26 x i8], [26 x i8]* @.str, i64 0, i64 0))
  %argc.addr.reloadbodyBB8cloneBB = load volatile i32*, i32** %argc.addr.reg2mem, align 8
  %478 = load i32, i32* %argc.addr.reloadbodyBB8cloneBB, align 4
  store i32 %478, i32* %.reg2mem, align 4
  %479 = sub i32 %20, 1
  %480 = add i32 %20, 3
  %481 = add i32 %20, 4
  %482 = sub i32 %20, 3
  %483 = mul i32 %479, %480
  %484 = mul i32 %481, %482
  %485 = sub i32 %483, %484
  %486 = sub i32 %485, 9
  %487 = and i32 %486, 1
  %488 = icmp eq i32 %487, 1
  br i1 %488, label %bodyBB8, label %endBB9

bodyBB10bodyBB10cloneBB:                          ; preds = %bodyBB10, %42
  %.reloadbodyBB10cloneBB = load volatile i32, i32* %.reg2mem, align 4
  %cmpbodyBB10cloneBB = icmp sle i32 %.reloadbodyBB10cloneBB, 1
  store i1 %cmpbodyBB10cloneBB, i1* %cmp.reg2mem, align 1
  %489 = sub i32 %44, 1
  %490 = add i32 %44, 3
  %491 = add i32 %44, 4
  %492 = sub i32 %44, 3
  %493 = mul i32 %489, %490
  %494 = mul i32 %491, %492
  %495 = sub i32 %493, %494
  %496 = sub i32 %495, 9
  %497 = and i32 %496, 1
  %498 = icmp eq i32 %497, 1
  br i1 %498, label %bodyBB10, label %endBB11

bodyBB12bodyBB12cloneBB:                          ; preds = %bodyBB12, %if.then
  %499 = sub i32 %66, 1
  %500 = add i32 %66, 3
  %501 = add i32 %66, 4
  %502 = sub i32 %66, 3
  %503 = mul i32 %499, %500
  %504 = mul i32 %501, %502
  %505 = sub i32 %503, %504
  %506 = sub i32 %505, 9
  %507 = and i32 %506, 1
  %508 = icmp eq i32 %507, 1
  br i1 %508, label %bodyBB12, label %endBB13

bodyBB14bodyBB14cloneBB:                          ; preds = %bodyBB14, %83
  %509 = sub i32 %85, 1
  %510 = add i32 %85, 3
  %511 = add i32 %85, 4
  %512 = sub i32 %85, 3
  %513 = mul i32 %509, %510
  %514 = mul i32 %511, %512
  %515 = sub i32 %513, %514
  %516 = sub i32 %515, 9
  %517 = and i32 %516, 1
  %518 = icmp eq i32 %517, 1
  br i1 %518, label %bodyBB14, label %endBB15

bodyBB16bodyBB16cloneBB:                          ; preds = %bodyBB16, %106
  %call1bodyBB16cloneBB = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([33 x i8], [33 x i8]* @.str.1, i64 0, i64 0))
  %retval.reload1bodyBB16cloneBB = load volatile i32*, i32** %retval.reg2mem, align 8
  store i32 0, i32* %retval.reload1bodyBB16cloneBB, align 4
  %519 = mul i32 %108, 3
  %520 = sub i32 %108, 2
  %521 = mul i32 %519, %520
  %522 = mul i32 %108, %108
  %523 = mul i32 %522, 3
  %524 = mul i32 %108, 7
  %525 = sub i32 %521, %523
  %526 = add i32 %524, %525
  %527 = and i32 %526, 1
  %528 = icmp eq i32 %527, 1
  br i1 %528, label %bodyBB16, label %endBB17

bodyBB18bodyBB18cloneBB:                          ; preds = %bodyBB18, %if.end
  %argv.addr.reloadbodyBB18cloneBB = load volatile i8***, i8**** %argv.addr.reg2mem, align 8
  %529 = load i8**, i8*** %argv.addr.reloadbodyBB18cloneBB, align 8
  %arrayidxbodyBB18cloneBB = getelementptr inbounds i8*, i8** %529, i64 1
  %530 = load i8*, i8** %arrayidxbodyBB18cloneBB, align 8
  store i8* %530, i8** @input, align 8
  %531 = load i8*, i8** @input, align 8
  %call2bodyBB18cloneBB = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([18 x i8], [18 x i8]* @.str.2, i64 0, i64 0), i8* %531)
  %532 = add i32 %130, 1
  %533 = mul i32 %130, %532
  %534 = mul i32 %130, %130
  %535 = sub i32 %533, %534
  %536 = and i32 %535, 1
  %537 = icmp eq i32 %536, 1
  br i1 %537, label %bodyBB18, label %endBB19

bodyBB20bodyBB20cloneBB:                          ; preds = %bodyBB20, %154
  %dest.reload6bodyBB20cloneBB = load volatile [100 x i8]*, [100 x i8]** %dest.reg2mem, align 8
  %538 = bitcast [100 x i8]* %dest.reload6bodyBB20cloneBB to i8*
  call void @llvm.memset.p0i8.i64(i8* align 16 %538, i8 0, i64 100, i1 false)
  %dest.reload5bodyBB20cloneBB = load volatile [100 x i8]*, [100 x i8]** %dest.reg2mem, align 8
  %arraydecaybodyBB20cloneBB = getelementptr inbounds [100 x i8], [100 x i8]* %dest.reload5bodyBB20cloneBB, i64 0, i64 0
  %539 = load i8*, i8** @input, align 8
  call void @_Z7encryptPhPc(i8* %arraydecaybodyBB20cloneBB, i8* %539)
  %540 = load i8*, i8** @input, align 8
  store i8* %540, i8** %.reg2mem22, align 8
  %541 = sub i32 %156, 1
  %542 = add i32 %156, 3
  %543 = add i32 %156, 4
  %544 = sub i32 %156, 3
  %545 = mul i32 %541, %542
  %546 = mul i32 %543, %544
  %547 = sub i32 %545, %546
  %548 = sub i32 %547, 9
  %549 = and i32 %548, 1
  %550 = icmp eq i32 %549, 1
  br i1 %550, label %bodyBB20, label %endBB21

bodyBB24bodyBB24cloneBB:                          ; preds = %bodyBB24, %180
  %.reload23bodyBB24cloneBB = load volatile i8*, i8** %.reg2mem22, align 8
  %call3bodyBB24cloneBB = call i64 @strlen(i8* %.reload23bodyBB24cloneBB) #6
  %cmp4bodyBB24cloneBB = icmp eq i64 %call3bodyBB24cloneBB, 22
  store i1 %cmp4bodyBB24cloneBB, i1* %cmp4.reg2mem, align 1
  %551 = sub i32 %182, 1
  %552 = add i32 %182, 3
  %553 = add i32 %182, 4
  %554 = sub i32 %182, 3
  %555 = mul i32 %551, %552
  %556 = mul i32 %553, %554
  %557 = sub i32 %555, %556
  %558 = sub i32 %557, 9
  %559 = and i32 %558, 1
  %560 = icmp eq i32 %559, 1
  br i1 %560, label %bodyBB24, label %endBB25

bodyBB26bodyBB26cloneBB:                          ; preds = %bodyBB26, %land.rhs
  %dest.reloadbodyBB26cloneBB = load volatile [100 x i8]*, [100 x i8]** %dest.reg2mem, align 8
  %arraydecay5bodyBB26cloneBB = getelementptr inbounds [100 x i8], [100 x i8]* %dest.reloadbodyBB26cloneBB, i64 0, i64 0
  store i8* %arraydecay5bodyBB26cloneBB, i8** %arraydecay5.reg2mem, align 8
  %561 = add i32 %200, 1
  %562 = mul i32 %200, %561
  %563 = mul i32 %200, %200
  %564 = sub i32 %562, %563
  %565 = and i32 %564, 1
  %566 = icmp eq i32 %565, 1
  br i1 %566, label %bodyBB26, label %endBB27

bodyBB28bodyBB28cloneBB:                          ; preds = %bodyBB28, %217
  %arraydecay5.reloadbodyBB28cloneBB = load volatile i8*, i8** %arraydecay5.reg2mem, align 8
  %call6bodyBB28cloneBB = call i32 @memcmp(i8* %arraydecay5.reloadbodyBB28cloneBB, i8* getelementptr inbounds ([100 x i8], [100 x i8]* bitcast (<{ [22 x i8], [78 x i8] }>* @enc to [100 x i8]*), i64 0, i64 0), i64 22) #6
  store i32 %call6bodyBB28cloneBB, i32* %call6.reg2mem, align 4
  %567 = add i32 %219, 1
  %568 = mul i32 %219, %567
  %569 = mul i32 %219, %219
  %570 = sub i32 %568, %569
  %571 = and i32 %570, 1
  %572 = icmp eq i32 %571, 1
  br i1 %572, label %bodyBB28, label %endBB29

bodyBB30bodyBB30cloneBB:                          ; preds = %bodyBB30, %240
  %call6.reloadbodyBB30cloneBB = load volatile i32, i32* %call6.reg2mem, align 4
  %toboolbodyBB30cloneBB = icmp ne i32 %call6.reloadbodyBB30cloneBB, 0
  %lnotbodyBB30cloneBB = xor i1 %toboolbodyBB30cloneBB, true
  store i1 %lnotbodyBB30cloneBB, i1* %lnot.reg2mem, align 1
  %573 = add i32 %242, 1
  %574 = mul i32 %242, %573
  %575 = mul i32 %242, %242
  %576 = sub i32 %574, %575
  %577 = and i32 %576, 1
  %578 = icmp eq i32 %577, 1
  br i1 %578, label %bodyBB30, label %endBB31

bodyBB32bodyBB32cloneBB:                          ; preds = %bodyBB32, %land.end
  %fromboolbodyBB32cloneBB = zext i1 %259 to i8
  %result.reload7bodyBB32cloneBB = load volatile i8*, i8** %result.reg2mem, align 8
  store i8 %fromboolbodyBB32cloneBB, i8* %result.reload7bodyBB32cloneBB, align 1
  %result.reloadbodyBB32cloneBB = load volatile i8*, i8** %result.reg2mem, align 8
  %579 = load i8, i8* %result.reloadbodyBB32cloneBB, align 1
  %tobool7bodyBB32cloneBB = trunc i8 %579 to i1
  store i1 %tobool7bodyBB32cloneBB, i1* %tobool7.reg2mem, align 1
  %580 = sub i32 %261, 1
  %581 = add i32 %261, 3
  %582 = add i32 %261, 4
  %583 = sub i32 %261, 3
  %584 = mul i32 %580, %581
  %585 = mul i32 %582, %583
  %586 = sub i32 %584, %585
  %587 = sub i32 %586, 9
  %588 = and i32 %587, 1
  %589 = icmp eq i32 %588, 1
  br i1 %589, label %bodyBB32, label %endBB33

bodyBB34bodyBB34cloneBB:                          ; preds = %bodyBB34, %if.then8
  %590 = add i32 %280, 1
  %591 = mul i32 %280, %590
  %592 = mul i32 %280, %280
  %593 = sub i32 %591, %592
  %594 = and i32 %593, 1
  %595 = icmp eq i32 %594, 1
  br i1 %595, label %bodyBB34, label %endBB35

bodyBB36bodyBB36cloneBB:                          ; preds = %bodyBB36, %301
  %596 = sub i32 %303, 1
  %597 = add i32 %303, 3
  %598 = add i32 %303, 4
  %599 = sub i32 %303, 3
  %600 = mul i32 %596, %597
  %601 = mul i32 %598, %599
  %602 = sub i32 %600, %601
  %603 = sub i32 %602, 9
  %604 = and i32 %603, 1
  %605 = icmp eq i32 %604, 1
  br i1 %605, label %bodyBB36, label %endBB37

bodyBB38bodyBB38cloneBB:                          ; preds = %bodyBB38, %320
  %call9bodyBB38cloneBB = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([18 x i8], [18 x i8]* @.str.3, i64 0, i64 0))
  %606 = sub i32 %322, 1
  %607 = add i32 %322, 3
  %608 = add i32 %322, 4
  %609 = sub i32 %322, 3
  %610 = mul i32 %606, %607
  %611 = mul i32 %608, %609
  %612 = sub i32 %610, %611
  %613 = sub i32 %612, 9
  %614 = and i32 %613, 1
  %615 = icmp eq i32 %614, 1
  br i1 %615, label %bodyBB38, label %endBB39

bodyBB40bodyBB40cloneBB:                          ; preds = %bodyBB40, %if.else
  %616 = add i32 %340, 1
  %617 = mul i32 %340, %616
  %618 = mul i32 %340, %340
  %619 = sub i32 %617, %618
  %620 = and i32 %619, 1
  %621 = icmp eq i32 %620, 1
  br i1 %621, label %bodyBB40, label %endBB41

bodyBB42bodyBB42cloneBB:                          ; preds = %bodyBB42, %361
  %622 = add i32 %363, 1
  %623 = mul i32 %363, %622
  %624 = mul i32 %363, %363
  %625 = sub i32 %623, %624
  %626 = and i32 %625, 1
  %627 = icmp eq i32 %626, 1
  br i1 %627, label %bodyBB42, label %endBB43

bodyBB44bodyBB44cloneBB:                          ; preds = %bodyBB44, %384
  %call10bodyBB44cloneBB = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([18 x i8], [18 x i8]* @.str.4, i64 0, i64 0))
  %628 = sub i32 %386, 1
  %629 = add i32 %386, 3
  %630 = add i32 %386, 4
  %631 = sub i32 %386, 3
  %632 = mul i32 %628, %629
  %633 = mul i32 %630, %631
  %634 = sub i32 %632, %633
  %635 = sub i32 %634, 9
  %636 = and i32 %635, 1
  %637 = icmp eq i32 %636, 1
  br i1 %637, label %bodyBB44, label %endBB45

bodyBB46bodyBB46cloneBB:                          ; preds = %bodyBB46, %if.end11
  %638 = sub i32 %404, 1
  %639 = add i32 %404, 3
  %640 = add i32 %404, 4
  %641 = sub i32 %404, 3
  %642 = mul i32 %638, %639
  %643 = mul i32 %640, %641
  %644 = sub i32 %642, %643
  %645 = sub i32 %644, 9
  %646 = and i32 %645, 1
  %647 = icmp eq i32 %646, 1
  br i1 %647, label %bodyBB46, label %endBB47

bodyBB48bodyBB48cloneBB:                          ; preds = %bodyBB48, %425
  %648 = mul i32 %427, 3
  %649 = sub i32 %427, 2
  %650 = mul i32 %648, %649
  %651 = mul i32 %427, %427
  %652 = mul i32 %651, 3
  %653 = mul i32 %427, 7
  %654 = sub i32 %650, %652
  %655 = add i32 %653, %654
  %656 = and i32 %655, 1
  %657 = icmp eq i32 %656, 1
  br i1 %657, label %bodyBB48, label %endBB49

bodyBB50bodyBB50cloneBB:                          ; preds = %bodyBB50, %444
  %retval.reloadbodyBB50cloneBB = load volatile i32*, i32** %retval.reg2mem, align 8
  %658 = load i32, i32* %retval.reloadbodyBB50cloneBB, align 4
  store i32 %658, i32* %.reg2mem52, align 4
  %659 = add i32 %446, 1
  %660 = mul i32 %446, %659
  %661 = mul i32 %446, %446
  %662 = sub i32 %660, %661
  %663 = and i32 %662, 1
  %664 = icmp eq i32 %663, 1
  br i1 %664, label %bodyBB50, label %endBB51
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
