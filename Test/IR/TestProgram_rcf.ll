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
  %inc.reg2mem = alloca i32, align 4
  %.reg2mem57 = alloca i32, align 4
  %arrayidx4.reg2mem = alloca i8*, align 8
  %conv2.reg2mem = alloca i8, align 1
  %sub.reg2mem = alloca i32, align 4
  %conv1.reg2mem = alloca i32, align 4
  %cmp.reg2mem = alloca i1, align 1
  %.reg2mem27 = alloca i32, align 4
  %.reg2mem = alloca i32, align 4
  %i.reg2mem = alloca i32*, align 8
  %len.reg2mem = alloca i32*, align 8
  %src.addr.reg2mem = alloca i8**, align 8
  %dest.addr.reg2mem = alloca i8**, align 8
  %0 = call { i32, i32 } @llvm.x86.rdrand.32()
  %1 = mul i32 1, 3
  %2 = sub i32 1, 2
  %3 = mul i32 %1, %2
  %4 = mul i32 1, 1
  %5 = mul i32 %4, 3
  %6 = mul i32 1, 7
  %7 = sub i32 %3, %5
  %8 = add i32 %6, %7
  %9 = and i32 %8, 1
  %10 = icmp eq i32 %9, 1
  br i1 %10, label %11, label %176

11:                                               ; preds = %entry
  %dest.addr = alloca i8*, align 8
  store i8** %dest.addr, i8*** %dest.addr.reg2mem, align 8
  %src.addr = alloca i8*, align 8
  store i8** %src.addr, i8*** %src.addr.reg2mem, align 8
  %len = alloca i32, align 4
  store i32* %len, i32** %len.reg2mem, align 8
  %i = alloca i32, align 4
  store i32* %i, i32** %i.reg2mem, align 8
  %dest.addr.reload2 = load volatile i8**, i8*** %dest.addr.reg2mem, align 8
  store i8* %dest, i8** %dest.addr.reload2, align 8
  br label %12

12:                                               ; preds = %176, %11
  br label %13

13:                                               ; preds = %12
  %14 = call { i32, i32 } @llvm.x86.rdrand.32()
  %15 = sub i32 1, 1
  %16 = add i32 1, 3
  %17 = add i32 1, 4
  %18 = sub i32 1, 3
  %19 = mul i32 %15, %16
  %20 = mul i32 %17, %18
  %21 = sub i32 %19, %20
  %22 = sub i32 %21, 9
  %23 = and i32 %22, 1
  %24 = icmp eq i32 %23, 1
  br i1 %24, label %25, label %177

25:                                               ; preds = %13
  %src.addr.reload7 = load volatile i8**, i8*** %src.addr.reg2mem, align 8
  store i8* %src, i8** %src.addr.reload7, align 8
  %src.addr.reload6 = load volatile i8**, i8*** %src.addr.reg2mem, align 8
  %26 = load i8*, i8** %src.addr.reload6, align 8
  %call = call i64 @strlen(i8* %26) #6
  %conv = trunc i64 %call to i32
  %len.reload10 = load volatile i32*, i32** %len.reg2mem, align 8
  store i32 %conv, i32* %len.reload10, align 4
  br label %27

27:                                               ; preds = %177, %25
  br label %28

28:                                               ; preds = %27
  %29 = call { i32, i32 } @llvm.x86.rdrand.32()
  %30 = sub i32 1, 1
  %31 = add i32 1, 3
  %32 = add i32 1, 4
  %33 = sub i32 1, 3
  %34 = mul i32 %30, %31
  %35 = mul i32 %32, %33
  %36 = sub i32 %34, %35
  %37 = sub i32 %36, 9
  %38 = and i32 %37, 1
  %39 = icmp eq i32 %38, 1
  br i1 %39, label %40, label %179

40:                                               ; preds = %28
  %i.reload25 = load volatile i32*, i32** %i.reg2mem, align 8
  store i32 0, i32* %i.reload25, align 4
  br label %41

41:                                               ; preds = %179, %40
  br label %for.cond

for.cond:                                         ; preds = %162, %41
  %42 = call { i32, i32 } @llvm.x86.rdrand.32()
  %43 = add i32 1, 1
  %44 = mul i32 1, %43
  %45 = mul i32 1, 1
  %46 = sub i32 %44, %45
  %47 = and i32 %46, 1
  %48 = icmp eq i32 %47, 1
  br i1 %48, label %49, label %180

49:                                               ; preds = %for.cond
  %i.reload24 = load volatile i32*, i32** %i.reg2mem, align 8
  %50 = load i32, i32* %i.reload24, align 4
  store i32 %50, i32* %.reg2mem, align 4
  br label %51

51:                                               ; preds = %180, %49
  br label %52

52:                                               ; preds = %51
  %53 = call { i32, i32 } @llvm.x86.rdrand.32()
  %54 = mul i32 1, 3
  %55 = sub i32 1, 2
  %56 = mul i32 %54, %55
  %57 = mul i32 1, 1
  %58 = mul i32 %57, 3
  %59 = mul i32 1, 7
  %60 = sub i32 %56, %58
  %61 = add i32 %59, %60
  %62 = and i32 %61, 1
  %63 = icmp eq i32 %62, 1
  br i1 %63, label %64, label %182

64:                                               ; preds = %52
  %len.reload9 = load volatile i32*, i32** %len.reg2mem, align 8
  %65 = load i32, i32* %len.reload9, align 4
  store i32 %65, i32* %.reg2mem27, align 4
  br label %66

66:                                               ; preds = %182, %64
  br label %67

67:                                               ; preds = %66
  %68 = call { i32, i32 } @llvm.x86.rdrand.32()
  %69 = sub i32 1, 1
  %70 = add i32 1, 3
  %71 = add i32 1, 4
  %72 = sub i32 1, 3
  %73 = mul i32 %69, %70
  %74 = mul i32 %71, %72
  %75 = sub i32 %73, %74
  %76 = sub i32 %75, 9
  %77 = and i32 %76, 1
  %78 = icmp eq i32 %77, 1
  br i1 %78, label %79, label %184

79:                                               ; preds = %67
  %.reload26 = load volatile i32, i32* %.reg2mem, align 4
  %.reload29 = load volatile i32, i32* %.reg2mem27, align 4
  %cmp = icmp slt i32 %.reload26, %.reload29
  store i1 %cmp, i1* %cmp.reg2mem, align 1
  br label %80

80:                                               ; preds = %184, %79
  %cmp.reload = load volatile i1, i1* %cmp.reg2mem, align 1
  br i1 %cmp.reload, label %for.body, label %for.end

for.body:                                         ; preds = %80
  %81 = call { i32, i32 } @llvm.x86.rdrand.32()
  %82 = add i32 1, 1
  %83 = mul i32 1, %82
  %84 = mul i32 1, 1
  %85 = sub i32 %83, %84
  %86 = and i32 %85, 1
  %87 = icmp eq i32 %86, 1
  br i1 %87, label %88, label %185

88:                                               ; preds = %for.body
  %src.addr.reload5 = load volatile i8**, i8*** %src.addr.reg2mem, align 8
  %89 = load i8*, i8** %src.addr.reload5, align 8
  %i.reload23 = load volatile i32*, i32** %i.reg2mem, align 8
  %90 = load i32, i32* %i.reload23, align 4
  %idxprom = sext i32 %90 to i64
  %arrayidx = getelementptr inbounds i8, i8* %89, i64 %idxprom
  %91 = load i8, i8* %arrayidx, align 1
  %conv1 = sext i8 %91 to i32
  store i32 %conv1, i32* %conv1.reg2mem, align 4
  %i.reload22 = load volatile i32*, i32** %i.reg2mem, align 8
  %92 = load i32, i32* %i.reload22, align 4
  %sub = sub nsw i32 32, %92
  store i32 %sub, i32* %sub.reg2mem, align 4
  br label %93

93:                                               ; preds = %185, %88
  br label %94

94:                                               ; preds = %93
  %95 = call { i32, i32 } @llvm.x86.rdrand.32()
  %96 = mul i32 1, 3
  %97 = sub i32 1, 2
  %98 = mul i32 %96, %97
  %99 = mul i32 1, 1
  %100 = mul i32 %99, 3
  %101 = mul i32 1, 7
  %102 = sub i32 %98, %100
  %103 = add i32 %101, %102
  %104 = and i32 %103, 1
  %105 = icmp eq i32 %104, 1
  br i1 %105, label %106, label %200

106:                                              ; preds = %94
  %conv1.reload40 = load volatile i32, i32* %conv1.reg2mem, align 4
  %sub.reload54 = load volatile i32, i32* %sub.reg2mem, align 4
  %add = add nsw i32 %conv1.reload40, %sub.reload54
  %i.reload21 = load volatile i32*, i32** %i.reg2mem, align 8
  %107 = load i32, i32* %i.reload21, align 4
  %xor = xor i32 %add, %107
  %conv2 = trunc i32 %xor to i8
  store i8 %conv2, i8* %conv2.reg2mem, align 1
  %dest.addr.reload1 = load volatile i8**, i8*** %dest.addr.reg2mem, align 8
  %108 = load i8*, i8** %dest.addr.reload1, align 8
  %i.reload20 = load volatile i32*, i32** %i.reg2mem, align 8
  %109 = load i32, i32* %i.reload20, align 4
  %idxprom3 = sext i32 %109 to i64
  %arrayidx4 = getelementptr inbounds i8, i8* %108, i64 %idxprom3
  store i8* %arrayidx4, i8** %arrayidx4.reg2mem, align 8
  br label %110

110:                                              ; preds = %200, %106
  br label %111

111:                                              ; preds = %110
  %112 = call { i32, i32 } @llvm.x86.rdrand.32()
  %113 = add i32 1, 1
  %114 = mul i32 1, %113
  %115 = mul i32 1, 1
  %116 = sub i32 %114, %115
  %117 = and i32 %116, 1
  %118 = icmp eq i32 %117, 1
  br i1 %118, label %119, label %233

119:                                              ; preds = %111
  %conv2.reload55 = load volatile i8, i8* %conv2.reg2mem, align 1
  %arrayidx4.reload56 = load volatile i8*, i8** %arrayidx4.reg2mem, align 8
  store i8 %conv2.reload55, i8* %arrayidx4.reload56, align 1
  br label %120

120:                                              ; preds = %233, %119
  br label %for.inc

for.inc:                                          ; preds = %120
  %121 = call { i32, i32 } @llvm.x86.rdrand.32()
  %122 = sub i32 1, 1
  %123 = add i32 1, 3
  %124 = add i32 1, 4
  %125 = sub i32 1, 3
  %126 = mul i32 %122, %123
  %127 = mul i32 %124, %125
  %128 = sub i32 %126, %127
  %129 = sub i32 %128, 9
  %130 = and i32 %129, 1
  %131 = icmp eq i32 %130, 1
  br i1 %131, label %132, label %234

132:                                              ; preds = %for.inc
  %i.reload19 = load volatile i32*, i32** %i.reg2mem, align 8
  %133 = load i32, i32* %i.reload19, align 4
  store i32 %133, i32* %.reg2mem57, align 4
  br label %134

134:                                              ; preds = %234, %132
  br label %135

135:                                              ; preds = %134
  %136 = call { i32, i32 } @llvm.x86.rdrand.32()
  %137 = sub i32 1, 1
  %138 = add i32 1, 3
  %139 = add i32 1, 4
  %140 = sub i32 1, 3
  %141 = mul i32 %137, %138
  %142 = mul i32 %139, %140
  %143 = sub i32 %141, %142
  %144 = sub i32 %143, 9
  %145 = and i32 %144, 1
  %146 = icmp eq i32 %145, 1
  br i1 %146, label %147, label %236

147:                                              ; preds = %135
  %.reload61 = load volatile i32, i32* %.reg2mem57, align 4
  %inc = add nsw i32 %.reload61, 1
  store i32 %inc, i32* %inc.reg2mem, align 4
  br label %148

148:                                              ; preds = %236, %147
  br label %149

149:                                              ; preds = %148
  %150 = call { i32, i32 } @llvm.x86.rdrand.32()
  %151 = mul i32 1, 3
  %152 = sub i32 1, 2
  %153 = mul i32 %151, %152
  %154 = mul i32 1, 1
  %155 = mul i32 %154, 3
  %156 = mul i32 1, 7
  %157 = sub i32 %153, %155
  %158 = add i32 %156, %157
  %159 = and i32 %158, 1
  %160 = icmp eq i32 %159, 1
  br i1 %160, label %161, label %241

161:                                              ; preds = %149
  %i.reload18 = load volatile i32*, i32** %i.reg2mem, align 8
  %inc.reload62 = load volatile i32, i32* %inc.reg2mem, align 4
  store i32 %inc.reload62, i32* %i.reload18, align 4
  br label %162

162:                                              ; preds = %241, %161
  br label %for.cond, !llvm.loop !2

for.end:                                          ; preds = %80
  %163 = call { i32, i32 } @llvm.x86.rdrand.32()
  %164 = mul i32 1, 3
  %165 = sub i32 1, 2
  %166 = mul i32 %164, %165
  %167 = mul i32 1, 1
  %168 = mul i32 %167, 3
  %169 = mul i32 1, 7
  %170 = sub i32 %166, %168
  %171 = add i32 %169, %170
  %172 = and i32 %171, 1
  %173 = icmp eq i32 %172, 1
  br i1 %173, label %174, label %242

174:                                              ; preds = %for.end
  br label %175

175:                                              ; preds = %242, %174
  ret void

176:                                              ; preds = %entry
  %dest.addr.clone = alloca i8*, align 8
  %src.addr.clone = alloca i8*, align 8
  %len.clone = alloca i32, align 4
  %i.clone = alloca i32, align 4
  store i8* %dest, i8** %dest.addr.clone, align 8
  br label %12

177:                                              ; preds = %13
  %src.addr.reload4 = load volatile i8**, i8*** %src.addr.reg2mem, align 8
  store i8* %src, i8** %src.addr.reload4, align 8
  %src.addr.reload3 = load volatile i8**, i8*** %src.addr.reg2mem, align 8
  %178 = load i8*, i8** %src.addr.reload3, align 8
  %call.clone = call i64 @strlen(i8* %178) #6
  %conv.clone = trunc i64 %call.clone to i32
  %len.reload8 = load volatile i32*, i32** %len.reg2mem, align 8
  store i32 %conv.clone, i32* %len.reload8, align 4
  br label %27

179:                                              ; preds = %28
  %i.reload17 = load volatile i32*, i32** %i.reg2mem, align 8
  store i32 0, i32* %i.reload17, align 4
  br label %41

180:                                              ; preds = %for.cond
  %i.reload16 = load volatile i32*, i32** %i.reg2mem, align 8
  %181 = load i32, i32* %i.reload16, align 4
  br label %51

182:                                              ; preds = %52
  %len.reload = load volatile i32*, i32** %len.reg2mem, align 8
  %183 = load i32, i32* %len.reload, align 4
  br label %66

184:                                              ; preds = %67
  %.reload = load volatile i32, i32* %.reg2mem, align 4
  %.reload28 = load volatile i32, i32* %.reg2mem27, align 4
  %cmp.clone = icmp slt i32 %.reload, %.reload28
  br label %80

185:                                              ; preds = %for.body
  %src.addr.reload = load volatile i8**, i8*** %src.addr.reg2mem, align 8
  %186 = load i8*, i8** %src.addr.reload, align 8
  %i.reload15 = load volatile i32*, i32** %i.reg2mem, align 8
  %187 = load i32, i32* %i.reload15, align 4
  %idxprom.clone = sext i32 %187 to i64
  %arrayidx.clone = getelementptr inbounds i8, i8* %186, i64 %idxprom.clone
  %188 = load i8, i8* %arrayidx.clone, align 1
  %conv1.clone = sext i8 %188 to i32
  %i.reload14 = load volatile i32*, i32** %i.reg2mem, align 8
  %189 = load i32, i32* %i.reload14, align 4
  %190 = shl i32 32, %189
  %191 = sub i32 0, 32
  %192 = add i32 %191, %189
  %193 = sub i32 32, %189
  %194 = mul i32 %193, %189
  %195 = sub i32 0, 32
  %196 = add i32 %195, %189
  %197 = shl i32 32, %189
  %198 = sub i32 0, 32
  %199 = add i32 %198, %189
  %sub.clone = sub nsw i32 32, %189
  br label %93

200:                                              ; preds = %94
  %conv1.reload38 = load volatile i32, i32* %conv1.reg2mem, align 4
  %sub.reload52 = load volatile i32, i32* %sub.reg2mem, align 4
  %201 = sub i32 %conv1.reload38, %sub.reload52
  %sub.reload51 = load volatile i32, i32* %sub.reg2mem, align 4
  %202 = mul i32 %201, %sub.reload51
  %conv1.reload37 = load volatile i32, i32* %conv1.reg2mem, align 4
  %sub.reload50 = load volatile i32, i32* %sub.reg2mem, align 4
  %203 = sub i32 %conv1.reload37, %sub.reload50
  %sub.reload49 = load volatile i32, i32* %sub.reg2mem, align 4
  %204 = mul i32 %203, %sub.reload49
  %conv1.reload36 = load volatile i32, i32* %conv1.reg2mem, align 4
  %205 = sub i32 0, %conv1.reload36
  %sub.reload48 = load volatile i32, i32* %sub.reg2mem, align 4
  %206 = add i32 %205, %sub.reload48
  %conv1.reload35 = load volatile i32, i32* %conv1.reg2mem, align 4
  %sub.reload47 = load volatile i32, i32* %sub.reg2mem, align 4
  %207 = shl i32 %conv1.reload35, %sub.reload47
  %conv1.reload34 = load volatile i32, i32* %conv1.reg2mem, align 4
  %208 = sub i32 0, %conv1.reload34
  %sub.reload46 = load volatile i32, i32* %sub.reg2mem, align 4
  %209 = add i32 %208, %sub.reload46
  %conv1.reload33 = load volatile i32, i32* %conv1.reg2mem, align 4
  %sub.reload45 = load volatile i32, i32* %sub.reg2mem, align 4
  %210 = shl i32 %conv1.reload33, %sub.reload45
  %conv1.reload32 = load volatile i32, i32* %conv1.reg2mem, align 4
  %211 = sub i32 0, %conv1.reload32
  %sub.reload44 = load volatile i32, i32* %sub.reg2mem, align 4
  %212 = add i32 %211, %sub.reload44
  %conv1.reload31 = load volatile i32, i32* %conv1.reg2mem, align 4
  %sub.reload43 = load volatile i32, i32* %sub.reg2mem, align 4
  %213 = shl i32 %conv1.reload31, %sub.reload43
  %conv1.reload30 = load volatile i32, i32* %conv1.reg2mem, align 4
  %sub.reload42 = load volatile i32, i32* %sub.reg2mem, align 4
  %214 = sub i32 %conv1.reload30, %sub.reload42
  %sub.reload41 = load volatile i32, i32* %sub.reg2mem, align 4
  %215 = mul i32 %214, %sub.reload41
  %conv1.reload = load volatile i32, i32* %conv1.reg2mem, align 4
  %216 = sub i32 0, %conv1.reload
  %sub.reload = load volatile i32, i32* %sub.reg2mem, align 4
  %217 = add i32 %216, %sub.reload
  %conv1.reload39 = load volatile i32, i32* %conv1.reg2mem, align 4
  %sub.reload53 = load volatile i32, i32* %sub.reg2mem, align 4
  %add.clone = add nsw i32 %conv1.reload39, %sub.reload53
  %i.reload13 = load volatile i32*, i32** %i.reg2mem, align 8
  %218 = load i32, i32* %i.reload13, align 4
  %219 = shl i32 %add.clone, %218
  %220 = shl i32 %add.clone, %218
  %221 = sub i32 0, %add.clone
  %222 = add i32 %221, %218
  %223 = sub i32 0, %add.clone
  %224 = add i32 %223, %218
  %225 = sub i32 %add.clone, %218
  %226 = mul i32 %225, %218
  %227 = sub i32 0, %add.clone
  %228 = add i32 %227, %218
  %229 = sub i32 0, %add.clone
  %230 = add i32 %229, %218
  %xor.clone = xor i32 %add.clone, %218
  %conv2.clone = trunc i32 %xor.clone to i8
  %dest.addr.reload = load volatile i8**, i8*** %dest.addr.reg2mem, align 8
  %231 = load i8*, i8** %dest.addr.reload, align 8
  %i.reload12 = load volatile i32*, i32** %i.reg2mem, align 8
  %232 = load i32, i32* %i.reload12, align 4
  %idxprom3.clone = sext i32 %232 to i64
  %arrayidx4.clone = getelementptr inbounds i8, i8* %231, i64 %idxprom3.clone
  br label %110

233:                                              ; preds = %111
  %conv2.reload = load volatile i8, i8* %conv2.reg2mem, align 1
  %arrayidx4.reload = load volatile i8*, i8** %arrayidx4.reg2mem, align 8
  store i8 %conv2.reload, i8* %arrayidx4.reload, align 1
  br label %120

234:                                              ; preds = %for.inc
  %i.reload11 = load volatile i32*, i32** %i.reg2mem, align 8
  %235 = load i32, i32* %i.reload11, align 4
  br label %134

236:                                              ; preds = %135
  %.reload59 = load volatile i32, i32* %.reg2mem57, align 4
  %237 = sub i32 0, %.reload59
  %238 = add i32 %237, 1
  %.reload58 = load volatile i32, i32* %.reg2mem57, align 4
  %239 = sub i32 0, %.reload58
  %240 = add i32 %239, 1
  %.reload60 = load volatile i32, i32* %.reg2mem57, align 4
  %inc.clone = add nsw i32 %.reload60, 1
  br label %148

241:                                              ; preds = %149
  %i.reload = load volatile i32*, i32** %i.reg2mem, align 8
  %inc.reload = load volatile i32, i32* %inc.reg2mem, align 4
  store i32 %inc.reload, i32* %i.reload, align 4
  br label %162

242:                                              ; preds = %for.end
  br label %175
}

; Function Attrs: nounwind readonly willreturn
declare dso_local i64 @strlen(i8*) #1

; Function Attrs: noinline norecurse optnone uwtable mustprogress
define dso_local i32 @main() #2 {
entry:
  %.reg2mem14 = alloca i32, align 4
  %tobool5.reg2mem = alloca i1, align 1
  %.reg2mem = alloca i1, align 1
  %lnot.reg2mem = alloca i1, align 1
  %call4.reg2mem = alloca i32, align 4
  %arraydecay3.reg2mem = alloca i8*, align 8
  %cmp.reg2mem = alloca i1, align 1
  %result.reg2mem = alloca i8*, align 8
  %dest.reg2mem = alloca [100 x i8]*, align 8
  %retval.reg2mem = alloca i32*, align 8
  %0 = call { i32, i32 } @llvm.x86.rdrand.32()
  %1 = mul i32 1, 3
  %2 = sub i32 1, 2
  %3 = mul i32 %1, %2
  %4 = mul i32 1, 1
  %5 = mul i32 %4, 3
  %6 = mul i32 1, 7
  %7 = sub i32 %3, %5
  %8 = add i32 %6, %7
  %9 = and i32 %8, 1
  %10 = icmp eq i32 %9, 1
  br i1 %10, label %11, label %214

11:                                               ; preds = %entry
  %retval = alloca i32, align 4
  store i32* %retval, i32** %retval.reg2mem, align 8
  %dest = alloca [100 x i8], align 16
  store [100 x i8]* %dest, [100 x i8]** %dest.reg2mem, align 8
  %result = alloca i8, align 1
  store i8* %result, i8** %result.reg2mem, align 8
  %retval.reload2 = load volatile i32*, i32** %retval.reg2mem, align 8
  store i32 0, i32* %retval.reload2, align 4
  %call = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([25 x i8], [25 x i8]* @.str, i64 0, i64 0))
  br label %12

12:                                               ; preds = %214, %11
  br label %13

13:                                               ; preds = %12
  %14 = call { i32, i32 } @llvm.x86.rdrand.32()
  %15 = mul i32 1, 3
  %16 = sub i32 1, 2
  %17 = mul i32 %15, %16
  %18 = mul i32 1, 1
  %19 = mul i32 %18, 3
  %20 = mul i32 1, 7
  %21 = sub i32 %17, %19
  %22 = add i32 %20, %21
  %23 = and i32 %22, 1
  %24 = icmp eq i32 %23, 1
  br i1 %24, label %25, label %215

25:                                               ; preds = %13
  %call1 = call i32 (i8*, ...) @scanf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @.str.1, i64 0, i64 0), i8* getelementptr inbounds ([100 x i8], [100 x i8]* @input, i64 0, i64 0))
  %dest.reload7 = load volatile [100 x i8]*, [100 x i8]** %dest.reg2mem, align 8
  %26 = bitcast [100 x i8]* %dest.reload7 to i8*
  call void @llvm.memset.p0i8.i64(i8* align 16 %26, i8 0, i64 100, i1 false)
  %dest.reload6 = load volatile [100 x i8]*, [100 x i8]** %dest.reg2mem, align 8
  %arraydecay = getelementptr inbounds [100 x i8], [100 x i8]* %dest.reload6, i64 0, i64 0
  call void @_Z7encryptPhPc(i8* %arraydecay, i8* getelementptr inbounds ([100 x i8], [100 x i8]* @input, i64 0, i64 0))
  br label %27

27:                                               ; preds = %215, %25
  br label %28

28:                                               ; preds = %27
  %29 = call { i32, i32 } @llvm.x86.rdrand.32()
  %30 = mul i32 1, 3
  %31 = sub i32 1, 2
  %32 = mul i32 %30, %31
  %33 = mul i32 1, 1
  %34 = mul i32 %33, 3
  %35 = mul i32 1, 7
  %36 = sub i32 %32, %34
  %37 = add i32 %35, %36
  %38 = and i32 %37, 1
  %39 = icmp eq i32 %38, 1
  br i1 %39, label %40, label %217

40:                                               ; preds = %28
  %call2 = call i64 @strlen(i8* getelementptr inbounds ([100 x i8], [100 x i8]* @input, i64 0, i64 0)) #6
  %cmp = icmp eq i64 %call2, 22
  store i1 %cmp, i1* %cmp.reg2mem, align 1
  br label %41

41:                                               ; preds = %217, %40
  %cmp.reload = load volatile i1, i1* %cmp.reg2mem, align 1
  br i1 %cmp.reload, label %land.rhs, label %land.end

land.rhs:                                         ; preds = %41
  %42 = call { i32, i32 } @llvm.x86.rdrand.32()
  %43 = add i32 1, 1
  %44 = mul i32 1, %43
  %45 = mul i32 1, 1
  %46 = sub i32 %44, %45
  %47 = and i32 %46, 1
  %48 = icmp eq i32 %47, 1
  br i1 %48, label %49, label %218

49:                                               ; preds = %land.rhs
  %dest.reload5 = load volatile [100 x i8]*, [100 x i8]** %dest.reg2mem, align 8
  %arraydecay3 = getelementptr inbounds [100 x i8], [100 x i8]* %dest.reload5, i64 0, i64 0
  store i8* %arraydecay3, i8** %arraydecay3.reg2mem, align 8
  br label %50

50:                                               ; preds = %218, %49
  br label %51

51:                                               ; preds = %50
  %52 = call { i32, i32 } @llvm.x86.rdrand.32()
  %53 = mul i32 1, 3
  %54 = sub i32 1, 2
  %55 = mul i32 %53, %54
  %56 = mul i32 1, 1
  %57 = mul i32 %56, 3
  %58 = mul i32 1, 7
  %59 = sub i32 %55, %57
  %60 = add i32 %58, %59
  %61 = and i32 %60, 1
  %62 = icmp eq i32 %61, 1
  br i1 %62, label %63, label %219

63:                                               ; preds = %51
  %arraydecay3.reload11 = load volatile i8*, i8** %arraydecay3.reg2mem, align 8
  %call4 = call i32 @memcmp(i8* %arraydecay3.reload11, i8* getelementptr inbounds ([100 x i8], [100 x i8]* bitcast (<{ [22 x i8], [78 x i8] }>* @enc to [100 x i8]*), i64 0, i64 0), i64 22) #6
  store i32 %call4, i32* %call4.reg2mem, align 4
  br label %64

64:                                               ; preds = %219, %63
  br label %65

65:                                               ; preds = %64
  %66 = call { i32, i32 } @llvm.x86.rdrand.32()
  %67 = mul i32 1, 3
  %68 = sub i32 1, 2
  %69 = mul i32 %67, %68
  %70 = mul i32 1, 1
  %71 = mul i32 %70, 3
  %72 = mul i32 1, 7
  %73 = sub i32 %69, %71
  %74 = add i32 %72, %73
  %75 = and i32 %74, 1
  %76 = icmp eq i32 %75, 1
  br i1 %76, label %77, label %220

77:                                               ; preds = %65
  %call4.reload12 = load volatile i32, i32* %call4.reg2mem, align 4
  %tobool = icmp ne i32 %call4.reload12, 0
  %lnot = xor i1 %tobool, true
  store i1 %lnot, i1* %lnot.reg2mem, align 1
  br label %78

78:                                               ; preds = %220, %77
  %lnot.reload = load volatile i1, i1* %lnot.reg2mem, align 1
  br label %land.end

land.end:                                         ; preds = %78, %41
  %79 = phi i1 [ false, %41 ], [ %lnot.reload, %78 ]
  store i1 %79, i1* %.reg2mem, align 1
  %80 = call { i32, i32 } @llvm.x86.rdrand.32()
  %81 = mul i32 1, 3
  %82 = sub i32 1, 2
  %83 = mul i32 %81, %82
  %84 = mul i32 1, 1
  %85 = mul i32 %84, 3
  %86 = mul i32 1, 7
  %87 = sub i32 %83, %85
  %88 = add i32 %86, %87
  %89 = and i32 %88, 1
  %90 = icmp eq i32 %89, 1
  br i1 %90, label %91, label %225

91:                                               ; preds = %land.end
  %.reload13 = load volatile i1, i1* %.reg2mem, align 1
  %frombool = zext i1 %.reload13 to i8
  %result.reload10 = load volatile i8*, i8** %result.reg2mem, align 8
  store i8 %frombool, i8* %result.reload10, align 1
  %result.reload9 = load volatile i8*, i8** %result.reg2mem, align 8
  %92 = load i8, i8* %result.reload9, align 1
  %tobool5 = trunc i8 %92 to i1
  store i1 %tobool5, i1* %tobool5.reg2mem, align 1
  br label %93

93:                                               ; preds = %225, %91
  %tobool5.reload = load volatile i1, i1* %tobool5.reg2mem, align 1
  br i1 %tobool5.reload, label %if.then, label %if.else

if.then:                                          ; preds = %93
  %94 = call { i32, i32 } @llvm.x86.rdrand.32()
  %95 = sub i32 1, 1
  %96 = add i32 1, 3
  %97 = add i32 1, 4
  %98 = sub i32 1, 3
  %99 = mul i32 %95, %96
  %100 = mul i32 %97, %98
  %101 = sub i32 %99, %100
  %102 = sub i32 %101, 9
  %103 = and i32 %102, 1
  %104 = icmp eq i32 %103, 1
  br i1 %104, label %105, label %227

105:                                              ; preds = %if.then
  br label %106

106:                                              ; preds = %227, %105
  br label %107

107:                                              ; preds = %106
  %108 = call { i32, i32 } @llvm.x86.rdrand.32()
  %109 = sub i32 1, 1
  %110 = add i32 1, 3
  %111 = add i32 1, 4
  %112 = sub i32 1, 3
  %113 = mul i32 %109, %110
  %114 = mul i32 %111, %112
  %115 = sub i32 %113, %114
  %116 = sub i32 %115, 9
  %117 = and i32 %116, 1
  %118 = icmp eq i32 %117, 1
  br i1 %118, label %119, label %228

119:                                              ; preds = %107
  br label %120

120:                                              ; preds = %228, %119
  br label %121

121:                                              ; preds = %120
  %122 = call { i32, i32 } @llvm.x86.rdrand.32()
  %123 = add i32 1, 1
  %124 = mul i32 1, %123
  %125 = mul i32 1, 1
  %126 = sub i32 %124, %125
  %127 = and i32 %126, 1
  %128 = icmp eq i32 %127, 1
  br i1 %128, label %129, label %229

129:                                              ; preds = %121
  %call6 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([18 x i8], [18 x i8]* @.str.2, i64 0, i64 0))
  br label %130

130:                                              ; preds = %229, %129
  br label %if.end

if.else:                                          ; preds = %93
  %131 = call { i32, i32 } @llvm.x86.rdrand.32()
  %132 = mul i32 1, 3
  %133 = sub i32 1, 2
  %134 = mul i32 %132, %133
  %135 = mul i32 1, 1
  %136 = mul i32 %135, 3
  %137 = mul i32 1, 7
  %138 = sub i32 %134, %136
  %139 = add i32 %137, %138
  %140 = and i32 %139, 1
  %141 = icmp eq i32 %140, 1
  br i1 %141, label %142, label %230

142:                                              ; preds = %if.else
  br label %143

143:                                              ; preds = %230, %142
  br label %144

144:                                              ; preds = %143
  %145 = call { i32, i32 } @llvm.x86.rdrand.32()
  %146 = sub i32 1, 1
  %147 = add i32 1, 3
  %148 = add i32 1, 4
  %149 = sub i32 1, 3
  %150 = mul i32 %146, %147
  %151 = mul i32 %148, %149
  %152 = sub i32 %150, %151
  %153 = sub i32 %152, 9
  %154 = and i32 %153, 1
  %155 = icmp eq i32 %154, 1
  br i1 %155, label %156, label %231

156:                                              ; preds = %144
  br label %157

157:                                              ; preds = %231, %156
  br label %158

158:                                              ; preds = %157
  %159 = call { i32, i32 } @llvm.x86.rdrand.32()
  %160 = mul i32 1, 3
  %161 = sub i32 1, 2
  %162 = mul i32 %160, %161
  %163 = mul i32 1, 1
  %164 = mul i32 %163, 3
  %165 = mul i32 1, 7
  %166 = sub i32 %162, %164
  %167 = add i32 %165, %166
  %168 = and i32 %167, 1
  %169 = icmp eq i32 %168, 1
  br i1 %169, label %170, label %232

170:                                              ; preds = %158
  %call7 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([18 x i8], [18 x i8]* @.str.3, i64 0, i64 0))
  br label %171

171:                                              ; preds = %232, %170
  br label %if.end

if.end:                                           ; preds = %171, %130
  %172 = call { i32, i32 } @llvm.x86.rdrand.32()
  %173 = sub i32 1, 1
  %174 = add i32 1, 3
  %175 = add i32 1, 4
  %176 = sub i32 1, 3
  %177 = mul i32 %173, %174
  %178 = mul i32 %175, %176
  %179 = sub i32 %177, %178
  %180 = sub i32 %179, 9
  %181 = and i32 %180, 1
  %182 = icmp eq i32 %181, 1
  br i1 %182, label %183, label %233

183:                                              ; preds = %if.end
  br label %184

184:                                              ; preds = %233, %183
  br label %185

185:                                              ; preds = %184
  %186 = call { i32, i32 } @llvm.x86.rdrand.32()
  %187 = sub i32 1, 1
  %188 = add i32 1, 3
  %189 = add i32 1, 4
  %190 = sub i32 1, 3
  %191 = mul i32 %187, %188
  %192 = mul i32 %189, %190
  %193 = sub i32 %191, %192
  %194 = sub i32 %193, 9
  %195 = and i32 %194, 1
  %196 = icmp eq i32 %195, 1
  br i1 %196, label %197, label %234

197:                                              ; preds = %185
  br label %198

198:                                              ; preds = %234, %197
  br label %199

199:                                              ; preds = %198
  %200 = call { i32, i32 } @llvm.x86.rdrand.32()
  %201 = sub i32 1, 1
  %202 = add i32 1, 3
  %203 = add i32 1, 4
  %204 = sub i32 1, 3
  %205 = mul i32 %201, %202
  %206 = mul i32 %203, %204
  %207 = sub i32 %205, %206
  %208 = sub i32 %207, 9
  %209 = and i32 %208, 1
  %210 = icmp eq i32 %209, 1
  br i1 %210, label %211, label %235

211:                                              ; preds = %199
  %retval.reload1 = load volatile i32*, i32** %retval.reg2mem, align 8
  %212 = load i32, i32* %retval.reload1, align 4
  store i32 %212, i32* %.reg2mem14, align 4
  br label %213

213:                                              ; preds = %235, %211
  %.reload15 = load volatile i32, i32* %.reg2mem14, align 4
  ret i32 %.reload15

214:                                              ; preds = %entry
  %retval.clone = alloca i32, align 4
  %dest.clone = alloca [100 x i8], align 16
  %result.clone = alloca i8, align 1
  store i32 0, i32* %retval.clone, align 4
  %call.clone = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([25 x i8], [25 x i8]* @.str, i64 0, i64 0))
  br label %12

215:                                              ; preds = %13
  %call1.clone = call i32 (i8*, ...) @scanf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @.str.1, i64 0, i64 0), i8* getelementptr inbounds ([100 x i8], [100 x i8]* @input, i64 0, i64 0))
  %dest.reload4 = load volatile [100 x i8]*, [100 x i8]** %dest.reg2mem, align 8
  %216 = bitcast [100 x i8]* %dest.reload4 to i8*
  call void @llvm.memset.p0i8.i64(i8* align 16 %216, i8 0, i64 100, i1 false)
  %dest.reload3 = load volatile [100 x i8]*, [100 x i8]** %dest.reg2mem, align 8
  %arraydecay.clone = getelementptr inbounds [100 x i8], [100 x i8]* %dest.reload3, i64 0, i64 0
  call void @_Z7encryptPhPc(i8* %arraydecay.clone, i8* getelementptr inbounds ([100 x i8], [100 x i8]* @input, i64 0, i64 0))
  br label %27

217:                                              ; preds = %28
  %call2.clone = call i64 @strlen(i8* getelementptr inbounds ([100 x i8], [100 x i8]* @input, i64 0, i64 0)) #6
  %cmp.clone = icmp eq i64 %call2.clone, 22
  br label %41

218:                                              ; preds = %land.rhs
  %dest.reload = load volatile [100 x i8]*, [100 x i8]** %dest.reg2mem, align 8
  %arraydecay3.clone = getelementptr inbounds [100 x i8], [100 x i8]* %dest.reload, i64 0, i64 0
  br label %50

219:                                              ; preds = %51
  %arraydecay3.reload = load volatile i8*, i8** %arraydecay3.reg2mem, align 8
  %call4.clone = call i32 @memcmp(i8* %arraydecay3.reload, i8* getelementptr inbounds ([100 x i8], [100 x i8]* bitcast (<{ [22 x i8], [78 x i8] }>* @enc to [100 x i8]*), i64 0, i64 0), i64 22) #6
  br label %64

220:                                              ; preds = %65
  %call4.reload = load volatile i32, i32* %call4.reg2mem, align 4
  %tobool.clone = icmp ne i32 %call4.reload, 0
  %221 = shl i1 %tobool.clone, true
  %222 = shl i1 %tobool.clone, true
  %223 = sub i1 false, %tobool.clone
  %224 = add i1 %223, true
  %lnot.clone = xor i1 %tobool.clone, true
  br label %78

225:                                              ; preds = %land.end
  %.reload = load volatile i1, i1* %.reg2mem, align 1
  %frombool.clone = zext i1 %.reload to i8
  %result.reload8 = load volatile i8*, i8** %result.reg2mem, align 8
  store i8 %frombool.clone, i8* %result.reload8, align 1
  %result.reload = load volatile i8*, i8** %result.reg2mem, align 8
  %226 = load i8, i8* %result.reload, align 1
  %tobool5.clone = trunc i8 %226 to i1
  br label %93

227:                                              ; preds = %if.then
  br label %106

228:                                              ; preds = %107
  br label %120

229:                                              ; preds = %121
  %call6.clone = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([18 x i8], [18 x i8]* @.str.2, i64 0, i64 0))
  br label %130

230:                                              ; preds = %if.else
  br label %143

231:                                              ; preds = %144
  br label %157

232:                                              ; preds = %158
  %call7.clone = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([18 x i8], [18 x i8]* @.str.3, i64 0, i64 0))
  br label %171

233:                                              ; preds = %if.end
  br label %184

234:                                              ; preds = %185
  br label %198

235:                                              ; preds = %199
  %retval.reload = load volatile i32*, i32** %retval.reg2mem, align 8
  %236 = load i32, i32* %retval.reload, align 4
  br label %213
}

declare dso_local i32 @printf(i8*, ...) #3

declare dso_local i32 @scanf(i8*, ...) #3

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
