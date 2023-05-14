
/*===- Generated file -------------------------------------------*- C++ -*-===*|*                                                                            *|
|* Introspection of available AST node SourceLocations                        *|
|*                                                                            *|
|* Automatically generated file, do not edit!                                 *|
|*                                                                            *|
\*===----------------------------------------------------------------------===*/

namespace clang {
namespace tooling {

using LocationAndString = SourceLocationMap::value_type;
using RangeAndString = SourceRangeMap::value_type;

bool NodeIntrospection::hasIntrospectionSupport() { return true; }

struct RecursionPopper
{
    RecursionPopper(std::vector<clang::TypeLoc> &TypeLocRecursionGuard)
    :  TLRG(TypeLocRecursionGuard)
    {

    }

    ~RecursionPopper()
    {
    TLRG.pop_back();
    }

private:
std::vector<clang::TypeLoc> &TLRG;
};

void GetLocationsImpl(SharedLocationCall const& Prefix,
    clang::CXXBaseSpecifier const *Object, SourceLocationMap &Locs,
    SourceRangeMap &Rngs,
    std::vector<clang::TypeLoc> &TypeLocRecursionGuard);

void GetLocationsImpl(SharedLocationCall const& Prefix,
    clang::CXXCtorInitializer const *Object, SourceLocationMap &Locs,
    SourceRangeMap &Rngs,
    std::vector<clang::TypeLoc> &TypeLocRecursionGuard);

void GetLocationsImpl(SharedLocationCall const& Prefix,
    clang::Decl const *Object, SourceLocationMap &Locs,
    SourceRangeMap &Rngs,
    std::vector<clang::TypeLoc> &TypeLocRecursionGuard);

void GetLocationsImpl(SharedLocationCall const& Prefix,
    clang::DeclarationNameInfo const &Object, SourceLocationMap &Locs,
    SourceRangeMap &Rngs,
    std::vector<clang::TypeLoc> &TypeLocRecursionGuard);

void GetLocationsImpl(SharedLocationCall const& Prefix,
    clang::NestedNameSpecifierLoc const &Object, SourceLocationMap &Locs,
    SourceRangeMap &Rngs,
    std::vector<clang::TypeLoc> &TypeLocRecursionGuard);

void GetLocationsImpl(SharedLocationCall const& Prefix,
    clang::Stmt const *Object, SourceLocationMap &Locs,
    SourceRangeMap &Rngs,
    std::vector<clang::TypeLoc> &TypeLocRecursionGuard);

void GetLocationsImpl(SharedLocationCall const& Prefix,
    clang::TemplateArgumentLoc const &Object, SourceLocationMap &Locs,
    SourceRangeMap &Rngs,
    std::vector<clang::TypeLoc> &TypeLocRecursionGuard);

void GetLocationsImpl(SharedLocationCall const& Prefix,
    clang::TypeLoc const &Object, SourceLocationMap &Locs,
    SourceRangeMap &Rngs,
    std::vector<clang::TypeLoc> &TypeLocRecursionGuard);

static void GetLocationsAbstractConditionalOperator(SharedLocationCall const& Prefix,
    clang::AbstractConditionalOperator const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{

  Locs.insert(LocationAndString(Object.getQuestionLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getQuestionLoc")));

  Locs.insert(LocationAndString(Object.getColonLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getColonLoc")));

}

static void GetLocationsAccessSpecDecl(SharedLocationCall const& Prefix,
    clang::AccessSpecDecl const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{

  Locs.insert(LocationAndString(Object.getAccessSpecifierLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getAccessSpecifierLoc")));

  Locs.insert(LocationAndString(Object.getColonLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getColonLoc")));

}

static void GetLocationsAddrLabelExpr(SharedLocationCall const& Prefix,
    clang::AddrLabelExpr const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{

  Locs.insert(LocationAndString(Object.getAmpAmpLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getAmpAmpLoc")));

  Locs.insert(LocationAndString(Object.getLabelLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getLabelLoc")));

}

static void GetLocationsAdjustedTypeLoc(SharedLocationCall const& Prefix,
    clang::AdjustedTypeLoc const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs , std::vector<clang::TypeLoc>& TypeLocRecursionGuard)
{


              if (Object.getOriginalLoc()) {
                GetLocationsImpl(
                    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getOriginalLoc"),
                    Object.getOriginalLoc(), Locs, Rngs, TypeLocRecursionGuard);
                }
              
}

static void GetLocationsArrayInitIndexExpr(SharedLocationCall const& Prefix,
    clang::ArrayInitIndexExpr const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{
}

static void GetLocationsArrayInitLoopExpr(SharedLocationCall const& Prefix,
    clang::ArrayInitLoopExpr const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{
}

static void GetLocationsArraySubscriptExpr(SharedLocationCall const& Prefix,
    clang::ArraySubscriptExpr const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{

  Locs.insert(LocationAndString(Object.getRBracketLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getRBracketLoc")));

}

static void GetLocationsArrayTypeLoc(SharedLocationCall const& Prefix,
    clang::ArrayTypeLoc const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs , std::vector<clang::TypeLoc>& TypeLocRecursionGuard)
{

  Locs.insert(LocationAndString(Object.getLBracketLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getLBracketLoc")));

  Locs.insert(LocationAndString(Object.getRBracketLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getRBracketLoc")));


  Rngs.insert(RangeAndString(Object.getBracketsRange(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getBracketsRange")));



              if (Object.getElementLoc()) {
                GetLocationsImpl(
                    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getElementLoc"),
                    Object.getElementLoc(), Locs, Rngs, TypeLocRecursionGuard);
                }
              
}

static void GetLocationsArrayTypeTraitExpr(SharedLocationCall const& Prefix,
    clang::ArrayTypeTraitExpr const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{
std::vector<clang::TypeLoc> TypeLocRecursionGuard;



              if (Object.getQueriedTypeSourceInfo()) {
                GetLocationsImpl(llvm::makeIntrusiveRefCnt<LocationCall>(
                    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getQueriedTypeSourceInfo",
                        LocationCall::ReturnsPointer), "getTypeLoc"),
                    Object.getQueriedTypeSourceInfo()->getTypeLoc(), Locs, Rngs, TypeLocRecursionGuard);
                    }
              
}

static void GetLocationsAsTypeExpr(SharedLocationCall const& Prefix,
    clang::AsTypeExpr const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{

  Locs.insert(LocationAndString(Object.getBuiltinLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getBuiltinLoc")));

  Locs.insert(LocationAndString(Object.getRParenLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getRParenLoc")));

}

static void GetLocationsAsmStmt(SharedLocationCall const& Prefix,
    clang::AsmStmt const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{

  Locs.insert(LocationAndString(Object.getAsmLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getAsmLoc")));

}

static void GetLocationsAtomicExpr(SharedLocationCall const& Prefix,
    clang::AtomicExpr const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{

  Locs.insert(LocationAndString(Object.getBuiltinLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getBuiltinLoc")));

  Locs.insert(LocationAndString(Object.getRParenLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getRParenLoc")));

}

static void GetLocationsAtomicTypeLoc(SharedLocationCall const& Prefix,
    clang::AtomicTypeLoc const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs , std::vector<clang::TypeLoc>& TypeLocRecursionGuard)
{

  Locs.insert(LocationAndString(Object.getKWLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getKWLoc")));

  Locs.insert(LocationAndString(Object.getLParenLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getLParenLoc")));

  Locs.insert(LocationAndString(Object.getRParenLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getRParenLoc")));


  Rngs.insert(RangeAndString(Object.getParensRange(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getParensRange")));



              if (Object.getValueLoc()) {
                GetLocationsImpl(
                    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getValueLoc"),
                    Object.getValueLoc(), Locs, Rngs, TypeLocRecursionGuard);
                }
              
}

static void GetLocationsAttributedStmt(SharedLocationCall const& Prefix,
    clang::AttributedStmt const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{

  Locs.insert(LocationAndString(Object.getAttrLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getAttrLoc")));

}

static void GetLocationsAttributedTypeLoc(SharedLocationCall const& Prefix,
    clang::AttributedTypeLoc const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs , std::vector<clang::TypeLoc>& TypeLocRecursionGuard)
{


              if (Object.getModifiedLoc()) {
                GetLocationsImpl(
                    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getModifiedLoc"),
                    Object.getModifiedLoc(), Locs, Rngs, TypeLocRecursionGuard);
                }
              
}

static void GetLocationsAutoTypeLoc(SharedLocationCall const& Prefix,
    clang::AutoTypeLoc const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs , std::vector<clang::TypeLoc>& TypeLocRecursionGuard)
{

  Locs.insert(LocationAndString(Object.getRParenLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getRParenLoc")));

  Locs.insert(LocationAndString(Object.getTemplateKWLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getTemplateKWLoc")));

  Locs.insert(LocationAndString(Object.getConceptNameLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getConceptNameLoc")));

  Locs.insert(LocationAndString(Object.getLAngleLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getLAngleLoc")));

  Locs.insert(LocationAndString(Object.getRAngleLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getRAngleLoc")));




                      GetLocationsImpl(
                          llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getConceptNameInfo"),
                          Object.getConceptNameInfo(), Locs, Rngs, TypeLocRecursionGuard);
                      }

static void GetLocationsBaseUsingDecl(SharedLocationCall const& Prefix,
    clang::BaseUsingDecl const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{
}

static void GetLocationsBinaryConditionalOperator(SharedLocationCall const& Prefix,
    clang::BinaryConditionalOperator const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{
}

static void GetLocationsBinaryOperator(SharedLocationCall const& Prefix,
    clang::BinaryOperator const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{

  Locs.insert(LocationAndString(Object.getOperatorLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getOperatorLoc")));

}

static void GetLocationsBindingDecl(SharedLocationCall const& Prefix,
    clang::BindingDecl const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{
}

static void GetLocationsBitIntTypeLoc(SharedLocationCall const& Prefix,
    clang::BitIntTypeLoc const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs , std::vector<clang::TypeLoc>& TypeLocRecursionGuard)
{
}

static void GetLocationsBlockDecl(SharedLocationCall const& Prefix,
    clang::BlockDecl const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{

  Locs.insert(LocationAndString(Object.getCaretLocation(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getCaretLocation")));

std::vector<clang::TypeLoc> TypeLocRecursionGuard;



              if (Object.getSignatureAsWritten()) {
                GetLocationsImpl(llvm::makeIntrusiveRefCnt<LocationCall>(
                    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getSignatureAsWritten",
                        LocationCall::ReturnsPointer), "getTypeLoc"),
                    Object.getSignatureAsWritten()->getTypeLoc(), Locs, Rngs, TypeLocRecursionGuard);
                    }
              
}

static void GetLocationsBlockExpr(SharedLocationCall const& Prefix,
    clang::BlockExpr const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{

  Locs.insert(LocationAndString(Object.getCaretLocation(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getCaretLocation")));

}

static void GetLocationsBlockPointerTypeLoc(SharedLocationCall const& Prefix,
    clang::BlockPointerTypeLoc const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs , std::vector<clang::TypeLoc>& TypeLocRecursionGuard)
{

  Locs.insert(LocationAndString(Object.getCaretLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getCaretLoc")));

}

static void GetLocationsBreakStmt(SharedLocationCall const& Prefix,
    clang::BreakStmt const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{

  Locs.insert(LocationAndString(Object.getBreakLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getBreakLoc")));

}

static void GetLocationsBuiltinBitCastExpr(SharedLocationCall const& Prefix,
    clang::BuiltinBitCastExpr const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{
}

static void GetLocationsBuiltinTemplateDecl(SharedLocationCall const& Prefix,
    clang::BuiltinTemplateDecl const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{
}

static void GetLocationsBuiltinTypeLoc(SharedLocationCall const& Prefix,
    clang::BuiltinTypeLoc const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs , std::vector<clang::TypeLoc>& TypeLocRecursionGuard)
{

  Locs.insert(LocationAndString(Object.getBuiltinLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getBuiltinLoc")));

  Locs.insert(LocationAndString(Object.getNameLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getNameLoc")));

}

static void GetLocationsCStyleCastExpr(SharedLocationCall const& Prefix,
    clang::CStyleCastExpr const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{

  Locs.insert(LocationAndString(Object.getLParenLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getLParenLoc")));

  Locs.insert(LocationAndString(Object.getRParenLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getRParenLoc")));

}

static void GetLocationsCUDAKernelCallExpr(SharedLocationCall const& Prefix,
    clang::CUDAKernelCallExpr const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{
}

static void GetLocationsCXXAddrspaceCastExpr(SharedLocationCall const& Prefix,
    clang::CXXAddrspaceCastExpr const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{
}

static void GetLocationsCXXBaseSpecifier(SharedLocationCall const& Prefix,
    clang::CXXBaseSpecifier const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{

  Locs.insert(LocationAndString(Object.getBeginLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getBeginLoc")));

  Locs.insert(LocationAndString(Object.getEndLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getEndLoc")));

  Locs.insert(LocationAndString(Object.getBaseTypeLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getBaseTypeLoc")));

  Locs.insert(LocationAndString(Object.getEllipsisLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getEllipsisLoc")));


  Rngs.insert(RangeAndString(Object.getSourceRange(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getSourceRange")));

std::vector<clang::TypeLoc> TypeLocRecursionGuard;



              if (Object.getTypeSourceInfo()) {
                GetLocationsImpl(llvm::makeIntrusiveRefCnt<LocationCall>(
                    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getTypeSourceInfo",
                        LocationCall::ReturnsPointer), "getTypeLoc"),
                    Object.getTypeSourceInfo()->getTypeLoc(), Locs, Rngs, TypeLocRecursionGuard);
                    }
              
}

static void GetLocationsCXXBindTemporaryExpr(SharedLocationCall const& Prefix,
    clang::CXXBindTemporaryExpr const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{
}

static void GetLocationsCXXBoolLiteralExpr(SharedLocationCall const& Prefix,
    clang::CXXBoolLiteralExpr const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{

  Locs.insert(LocationAndString(Object.getLocation(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getLocation")));

}

static void GetLocationsCXXCatchStmt(SharedLocationCall const& Prefix,
    clang::CXXCatchStmt const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{

  Locs.insert(LocationAndString(Object.getCatchLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getCatchLoc")));

}

static void GetLocationsCXXConstCastExpr(SharedLocationCall const& Prefix,
    clang::CXXConstCastExpr const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{
}

static void GetLocationsCXXConstructExpr(SharedLocationCall const& Prefix,
    clang::CXXConstructExpr const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{

  Locs.insert(LocationAndString(Object.getLocation(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getLocation")));


  Rngs.insert(RangeAndString(Object.getParenOrBraceRange(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getParenOrBraceRange")));

}

static void GetLocationsCXXConstructorDecl(SharedLocationCall const& Prefix,
    clang::CXXConstructorDecl const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{
}

static void GetLocationsCXXConversionDecl(SharedLocationCall const& Prefix,
    clang::CXXConversionDecl const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{
}

static void GetLocationsCXXCtorInitializer(SharedLocationCall const& Prefix,
    clang::CXXCtorInitializer const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{

  Locs.insert(LocationAndString(Object.getEllipsisLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getEllipsisLoc")));

  Locs.insert(LocationAndString(Object.getMemberLocation(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getMemberLocation")));

  Locs.insert(LocationAndString(Object.getSourceLocation(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getSourceLocation")));

  Locs.insert(LocationAndString(Object.getLParenLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getLParenLoc")));

  Locs.insert(LocationAndString(Object.getRParenLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getRParenLoc")));


  Rngs.insert(RangeAndString(Object.getSourceRange(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getSourceRange")));

std::vector<clang::TypeLoc> TypeLocRecursionGuard;


              if (Object.getBaseClassLoc()) {
                GetLocationsImpl(
                    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getBaseClassLoc"),
                    Object.getBaseClassLoc(), Locs, Rngs, TypeLocRecursionGuard);
                }
              

              if (Object.getTypeSourceInfo()) {
                GetLocationsImpl(llvm::makeIntrusiveRefCnt<LocationCall>(
                    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getTypeSourceInfo",
                        LocationCall::ReturnsPointer), "getTypeLoc"),
                    Object.getTypeSourceInfo()->getTypeLoc(), Locs, Rngs, TypeLocRecursionGuard);
                    }
              
}

static void GetLocationsCXXDeductionGuideDecl(SharedLocationCall const& Prefix,
    clang::CXXDeductionGuideDecl const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{
}

static void GetLocationsCXXDefaultArgExpr(SharedLocationCall const& Prefix,
    clang::CXXDefaultArgExpr const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{

  Locs.insert(LocationAndString(Object.getUsedLocation(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getUsedLocation")));

}

static void GetLocationsCXXDefaultInitExpr(SharedLocationCall const& Prefix,
    clang::CXXDefaultInitExpr const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{

  Locs.insert(LocationAndString(Object.getUsedLocation(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getUsedLocation")));

}

static void GetLocationsCXXDeleteExpr(SharedLocationCall const& Prefix,
    clang::CXXDeleteExpr const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{
}

static void GetLocationsCXXDependentScopeMemberExpr(SharedLocationCall const& Prefix,
    clang::CXXDependentScopeMemberExpr const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{

  Locs.insert(LocationAndString(Object.getOperatorLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getOperatorLoc")));

  Locs.insert(LocationAndString(Object.getMemberLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getMemberLoc")));

  Locs.insert(LocationAndString(Object.getTemplateKeywordLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getTemplateKeywordLoc")));

  Locs.insert(LocationAndString(Object.getLAngleLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getLAngleLoc")));

  Locs.insert(LocationAndString(Object.getRAngleLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getRAngleLoc")));

std::vector<clang::TypeLoc> TypeLocRecursionGuard;



              if (Object.getQualifierLoc())
                GetLocationsImpl(
                    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getQualifierLoc"),
                    Object.getQualifierLoc(), Locs, Rngs, TypeLocRecursionGuard);
              
                      GetLocationsImpl(
                          llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getMemberNameInfo"),
                          Object.getMemberNameInfo(), Locs, Rngs, TypeLocRecursionGuard);
                      }

static void GetLocationsCXXDestructorDecl(SharedLocationCall const& Prefix,
    clang::CXXDestructorDecl const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{
}

static void GetLocationsCXXDynamicCastExpr(SharedLocationCall const& Prefix,
    clang::CXXDynamicCastExpr const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{
}

static void GetLocationsCXXFoldExpr(SharedLocationCall const& Prefix,
    clang::CXXFoldExpr const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{

  Locs.insert(LocationAndString(Object.getLParenLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getLParenLoc")));

  Locs.insert(LocationAndString(Object.getRParenLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getRParenLoc")));

  Locs.insert(LocationAndString(Object.getEllipsisLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getEllipsisLoc")));

}

static void GetLocationsCXXForRangeStmt(SharedLocationCall const& Prefix,
    clang::CXXForRangeStmt const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{

  Locs.insert(LocationAndString(Object.getForLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getForLoc")));

  Locs.insert(LocationAndString(Object.getCoawaitLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getCoawaitLoc")));

  Locs.insert(LocationAndString(Object.getColonLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getColonLoc")));

  Locs.insert(LocationAndString(Object.getRParenLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getRParenLoc")));

}

static void GetLocationsCXXFunctionalCastExpr(SharedLocationCall const& Prefix,
    clang::CXXFunctionalCastExpr const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{

  Locs.insert(LocationAndString(Object.getLParenLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getLParenLoc")));

  Locs.insert(LocationAndString(Object.getRParenLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getRParenLoc")));

}

static void GetLocationsCXXInheritedCtorInitExpr(SharedLocationCall const& Prefix,
    clang::CXXInheritedCtorInitExpr const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{

  Locs.insert(LocationAndString(Object.getLocation(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getLocation")));

}

static void GetLocationsCXXMemberCallExpr(SharedLocationCall const& Prefix,
    clang::CXXMemberCallExpr const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{
}

static void GetLocationsCXXMethodDecl(SharedLocationCall const& Prefix,
    clang::CXXMethodDecl const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{
}

static void GetLocationsCXXNamedCastExpr(SharedLocationCall const& Prefix,
    clang::CXXNamedCastExpr const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{

  Locs.insert(LocationAndString(Object.getOperatorLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getOperatorLoc")));

  Locs.insert(LocationAndString(Object.getRParenLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getRParenLoc")));


  Rngs.insert(RangeAndString(Object.getAngleBrackets(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getAngleBrackets")));

}

static void GetLocationsCXXNewExpr(SharedLocationCall const& Prefix,
    clang::CXXNewExpr const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{

  Rngs.insert(RangeAndString(Object.getTypeIdParens(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getTypeIdParens")));

  Rngs.insert(RangeAndString(Object.getDirectInitRange(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getDirectInitRange")));

std::vector<clang::TypeLoc> TypeLocRecursionGuard;



              if (Object.getAllocatedTypeSourceInfo()) {
                GetLocationsImpl(llvm::makeIntrusiveRefCnt<LocationCall>(
                    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getAllocatedTypeSourceInfo",
                        LocationCall::ReturnsPointer), "getTypeLoc"),
                    Object.getAllocatedTypeSourceInfo()->getTypeLoc(), Locs, Rngs, TypeLocRecursionGuard);
                    }
              
}

static void GetLocationsCXXNoexceptExpr(SharedLocationCall const& Prefix,
    clang::CXXNoexceptExpr const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{
}

static void GetLocationsCXXNullPtrLiteralExpr(SharedLocationCall const& Prefix,
    clang::CXXNullPtrLiteralExpr const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{

  Locs.insert(LocationAndString(Object.getLocation(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getLocation")));

}

static void GetLocationsCXXOperatorCallExpr(SharedLocationCall const& Prefix,
    clang::CXXOperatorCallExpr const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{

  Locs.insert(LocationAndString(Object.getOperatorLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getOperatorLoc")));

}

static void GetLocationsCXXPseudoDestructorExpr(SharedLocationCall const& Prefix,
    clang::CXXPseudoDestructorExpr const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{

  Locs.insert(LocationAndString(Object.getOperatorLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getOperatorLoc")));

  Locs.insert(LocationAndString(Object.getColonColonLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getColonColonLoc")));

  Locs.insert(LocationAndString(Object.getTildeLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getTildeLoc")));

  Locs.insert(LocationAndString(Object.getDestroyedTypeLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getDestroyedTypeLoc")));

std::vector<clang::TypeLoc> TypeLocRecursionGuard;



              if (Object.getScopeTypeInfo()) {
                GetLocationsImpl(llvm::makeIntrusiveRefCnt<LocationCall>(
                    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getScopeTypeInfo",
                        LocationCall::ReturnsPointer), "getTypeLoc"),
                    Object.getScopeTypeInfo()->getTypeLoc(), Locs, Rngs, TypeLocRecursionGuard);
                    }
              
              if (Object.getDestroyedTypeInfo()) {
                GetLocationsImpl(llvm::makeIntrusiveRefCnt<LocationCall>(
                    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getDestroyedTypeInfo",
                        LocationCall::ReturnsPointer), "getTypeLoc"),
                    Object.getDestroyedTypeInfo()->getTypeLoc(), Locs, Rngs, TypeLocRecursionGuard);
                    }
              

              if (Object.getQualifierLoc())
                GetLocationsImpl(
                    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getQualifierLoc"),
                    Object.getQualifierLoc(), Locs, Rngs, TypeLocRecursionGuard);
              }

static void GetLocationsCXXRecordDecl(SharedLocationCall const& Prefix,
    clang::CXXRecordDecl const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{
std::vector<clang::TypeLoc> TypeLocRecursionGuard;



              if (Object.getLambdaTypeInfo()) {
                GetLocationsImpl(llvm::makeIntrusiveRefCnt<LocationCall>(
                    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getLambdaTypeInfo",
                        LocationCall::ReturnsPointer), "getTypeLoc"),
                    Object.getLambdaTypeInfo()->getTypeLoc(), Locs, Rngs, TypeLocRecursionGuard);
                    }
              
}

static void GetLocationsCXXReinterpretCastExpr(SharedLocationCall const& Prefix,
    clang::CXXReinterpretCastExpr const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{
}

static void GetLocationsCXXRewrittenBinaryOperator(SharedLocationCall const& Prefix,
    clang::CXXRewrittenBinaryOperator const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{

  Locs.insert(LocationAndString(Object.getOperatorLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getOperatorLoc")));

}

static void GetLocationsCXXScalarValueInitExpr(SharedLocationCall const& Prefix,
    clang::CXXScalarValueInitExpr const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{

  Locs.insert(LocationAndString(Object.getRParenLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getRParenLoc")));

std::vector<clang::TypeLoc> TypeLocRecursionGuard;



              if (Object.getTypeSourceInfo()) {
                GetLocationsImpl(llvm::makeIntrusiveRefCnt<LocationCall>(
                    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getTypeSourceInfo",
                        LocationCall::ReturnsPointer), "getTypeLoc"),
                    Object.getTypeSourceInfo()->getTypeLoc(), Locs, Rngs, TypeLocRecursionGuard);
                    }
              
}

static void GetLocationsCXXStaticCastExpr(SharedLocationCall const& Prefix,
    clang::CXXStaticCastExpr const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{
}

static void GetLocationsCXXStdInitializerListExpr(SharedLocationCall const& Prefix,
    clang::CXXStdInitializerListExpr const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{
}

static void GetLocationsCXXTemporaryObjectExpr(SharedLocationCall const& Prefix,
    clang::CXXTemporaryObjectExpr const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{
std::vector<clang::TypeLoc> TypeLocRecursionGuard;



              if (Object.getTypeSourceInfo()) {
                GetLocationsImpl(llvm::makeIntrusiveRefCnt<LocationCall>(
                    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getTypeSourceInfo",
                        LocationCall::ReturnsPointer), "getTypeLoc"),
                    Object.getTypeSourceInfo()->getTypeLoc(), Locs, Rngs, TypeLocRecursionGuard);
                    }
              
}

static void GetLocationsCXXThisExpr(SharedLocationCall const& Prefix,
    clang::CXXThisExpr const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{

  Locs.insert(LocationAndString(Object.getLocation(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getLocation")));

}

static void GetLocationsCXXThrowExpr(SharedLocationCall const& Prefix,
    clang::CXXThrowExpr const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{

  Locs.insert(LocationAndString(Object.getThrowLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getThrowLoc")));

}

static void GetLocationsCXXTryStmt(SharedLocationCall const& Prefix,
    clang::CXXTryStmt const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{

  Locs.insert(LocationAndString(Object.getTryLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getTryLoc")));

}

static void GetLocationsCXXTypeidExpr(SharedLocationCall const& Prefix,
    clang::CXXTypeidExpr const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{
std::vector<clang::TypeLoc> TypeLocRecursionGuard;



              if (Object.getTypeOperandSourceInfo()) {
                GetLocationsImpl(llvm::makeIntrusiveRefCnt<LocationCall>(
                    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getTypeOperandSourceInfo",
                        LocationCall::ReturnsPointer), "getTypeLoc"),
                    Object.getTypeOperandSourceInfo()->getTypeLoc(), Locs, Rngs, TypeLocRecursionGuard);
                    }
              
}

static void GetLocationsCXXUnresolvedConstructExpr(SharedLocationCall const& Prefix,
    clang::CXXUnresolvedConstructExpr const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{

  Locs.insert(LocationAndString(Object.getLParenLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getLParenLoc")));

  Locs.insert(LocationAndString(Object.getRParenLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getRParenLoc")));

std::vector<clang::TypeLoc> TypeLocRecursionGuard;



              if (Object.getTypeSourceInfo()) {
                GetLocationsImpl(llvm::makeIntrusiveRefCnt<LocationCall>(
                    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getTypeSourceInfo",
                        LocationCall::ReturnsPointer), "getTypeLoc"),
                    Object.getTypeSourceInfo()->getTypeLoc(), Locs, Rngs, TypeLocRecursionGuard);
                    }
              
}

static void GetLocationsCXXUuidofExpr(SharedLocationCall const& Prefix,
    clang::CXXUuidofExpr const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{
std::vector<clang::TypeLoc> TypeLocRecursionGuard;



              if (Object.getTypeOperandSourceInfo()) {
                GetLocationsImpl(llvm::makeIntrusiveRefCnt<LocationCall>(
                    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getTypeOperandSourceInfo",
                        LocationCall::ReturnsPointer), "getTypeLoc"),
                    Object.getTypeOperandSourceInfo()->getTypeLoc(), Locs, Rngs, TypeLocRecursionGuard);
                    }
              
}

static void GetLocationsCallExpr(SharedLocationCall const& Prefix,
    clang::CallExpr const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{

  Locs.insert(LocationAndString(Object.getRParenLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getRParenLoc")));

}

static void GetLocationsCapturedDecl(SharedLocationCall const& Prefix,
    clang::CapturedDecl const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{
}

static void GetLocationsCapturedStmt(SharedLocationCall const& Prefix,
    clang::CapturedStmt const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{
}

static void GetLocationsCaseStmt(SharedLocationCall const& Prefix,
    clang::CaseStmt const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{

  Locs.insert(LocationAndString(Object.getCaseLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getCaseLoc")));

  Locs.insert(LocationAndString(Object.getEllipsisLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getEllipsisLoc")));

}

static void GetLocationsCastExpr(SharedLocationCall const& Prefix,
    clang::CastExpr const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{
}

static void GetLocationsCharacterLiteral(SharedLocationCall const& Prefix,
    clang::CharacterLiteral const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{

  Locs.insert(LocationAndString(Object.getLocation(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getLocation")));

}

static void GetLocationsChooseExpr(SharedLocationCall const& Prefix,
    clang::ChooseExpr const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{

  Locs.insert(LocationAndString(Object.getBuiltinLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getBuiltinLoc")));

  Locs.insert(LocationAndString(Object.getRParenLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getRParenLoc")));

}

static void GetLocationsClassScopeFunctionSpecializationDecl(SharedLocationCall const& Prefix,
    clang::ClassScopeFunctionSpecializationDecl const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{
}

static void GetLocationsClassTemplateDecl(SharedLocationCall const& Prefix,
    clang::ClassTemplateDecl const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{
}

static void GetLocationsClassTemplatePartialSpecializationDecl(SharedLocationCall const& Prefix,
    clang::ClassTemplatePartialSpecializationDecl const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{
}

static void GetLocationsClassTemplateSpecializationDecl(SharedLocationCall const& Prefix,
    clang::ClassTemplateSpecializationDecl const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{

  Locs.insert(LocationAndString(Object.getPointOfInstantiation(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getPointOfInstantiation")));

  Locs.insert(LocationAndString(Object.getExternLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getExternLoc")));

  Locs.insert(LocationAndString(Object.getTemplateKeywordLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getTemplateKeywordLoc")));

std::vector<clang::TypeLoc> TypeLocRecursionGuard;



              if (Object.getTypeAsWritten()) {
                GetLocationsImpl(llvm::makeIntrusiveRefCnt<LocationCall>(
                    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getTypeAsWritten",
                        LocationCall::ReturnsPointer), "getTypeLoc"),
                    Object.getTypeAsWritten()->getTypeLoc(), Locs, Rngs, TypeLocRecursionGuard);
                    }
              
}

static void GetLocationsCoawaitExpr(SharedLocationCall const& Prefix,
    clang::CoawaitExpr const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{
}

static void GetLocationsComplexTypeLoc(SharedLocationCall const& Prefix,
    clang::ComplexTypeLoc const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs , std::vector<clang::TypeLoc>& TypeLocRecursionGuard)
{
}

static void GetLocationsCompoundAssignOperator(SharedLocationCall const& Prefix,
    clang::CompoundAssignOperator const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{
}

static void GetLocationsCompoundLiteralExpr(SharedLocationCall const& Prefix,
    clang::CompoundLiteralExpr const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{

  Locs.insert(LocationAndString(Object.getLParenLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getLParenLoc")));

std::vector<clang::TypeLoc> TypeLocRecursionGuard;



              if (Object.getTypeSourceInfo()) {
                GetLocationsImpl(llvm::makeIntrusiveRefCnt<LocationCall>(
                    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getTypeSourceInfo",
                        LocationCall::ReturnsPointer), "getTypeLoc"),
                    Object.getTypeSourceInfo()->getTypeLoc(), Locs, Rngs, TypeLocRecursionGuard);
                    }
              
}

static void GetLocationsCompoundStmt(SharedLocationCall const& Prefix,
    clang::CompoundStmt const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{

  Locs.insert(LocationAndString(Object.getLBracLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getLBracLoc")));

  Locs.insert(LocationAndString(Object.getRBracLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getRBracLoc")));

}

static void GetLocationsConceptDecl(SharedLocationCall const& Prefix,
    clang::ConceptDecl const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{
}

static void GetLocationsConceptSpecializationExpr(SharedLocationCall const& Prefix,
    clang::ConceptSpecializationExpr const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{
}

static void GetLocationsConditionalOperator(SharedLocationCall const& Prefix,
    clang::ConditionalOperator const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{
}

static void GetLocationsConstantArrayTypeLoc(SharedLocationCall const& Prefix,
    clang::ConstantArrayTypeLoc const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs , std::vector<clang::TypeLoc>& TypeLocRecursionGuard)
{
}

static void GetLocationsConstantExpr(SharedLocationCall const& Prefix,
    clang::ConstantExpr const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{
}

static void GetLocationsConstantMatrixTypeLoc(SharedLocationCall const& Prefix,
    clang::ConstantMatrixTypeLoc const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs , std::vector<clang::TypeLoc>& TypeLocRecursionGuard)
{
}

static void GetLocationsConstructorUsingShadowDecl(SharedLocationCall const& Prefix,
    clang::ConstructorUsingShadowDecl const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{
}

static void GetLocationsContinueStmt(SharedLocationCall const& Prefix,
    clang::ContinueStmt const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{

  Locs.insert(LocationAndString(Object.getContinueLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getContinueLoc")));

}

static void GetLocationsConvertVectorExpr(SharedLocationCall const& Prefix,
    clang::ConvertVectorExpr const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{

  Locs.insert(LocationAndString(Object.getBuiltinLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getBuiltinLoc")));

  Locs.insert(LocationAndString(Object.getRParenLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getRParenLoc")));

std::vector<clang::TypeLoc> TypeLocRecursionGuard;



              if (Object.getTypeSourceInfo()) {
                GetLocationsImpl(llvm::makeIntrusiveRefCnt<LocationCall>(
                    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getTypeSourceInfo",
                        LocationCall::ReturnsPointer), "getTypeLoc"),
                    Object.getTypeSourceInfo()->getTypeLoc(), Locs, Rngs, TypeLocRecursionGuard);
                    }
              
}

static void GetLocationsCoreturnStmt(SharedLocationCall const& Prefix,
    clang::CoreturnStmt const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{

  Locs.insert(LocationAndString(Object.getKeywordLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getKeywordLoc")));

}

static void GetLocationsCoroutineBodyStmt(SharedLocationCall const& Prefix,
    clang::CoroutineBodyStmt const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{
}

static void GetLocationsCoroutineSuspendExpr(SharedLocationCall const& Prefix,
    clang::CoroutineSuspendExpr const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{

  Locs.insert(LocationAndString(Object.getKeywordLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getKeywordLoc")));

}

static void GetLocationsCoyieldExpr(SharedLocationCall const& Prefix,
    clang::CoyieldExpr const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{
}

static void GetLocationsDecayedTypeLoc(SharedLocationCall const& Prefix,
    clang::DecayedTypeLoc const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs , std::vector<clang::TypeLoc>& TypeLocRecursionGuard)
{
}

static void GetLocationsDecl(SharedLocationCall const& Prefix,
    clang::Decl const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{

  Locs.insert(LocationAndString(Object.getBeginLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getBeginLoc")));

  Locs.insert(LocationAndString(Object.getEndLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getEndLoc")));

  Locs.insert(LocationAndString(Object.getLocation(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getLocation")));

  Locs.insert(LocationAndString(Object.getBodyRBrace(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getBodyRBrace")));


  Rngs.insert(RangeAndString(Object.getSourceRange(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getSourceRange")));

}

static void GetLocationsDeclRefExpr(SharedLocationCall const& Prefix,
    clang::DeclRefExpr const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{

  Locs.insert(LocationAndString(Object.getLocation(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getLocation")));

  Locs.insert(LocationAndString(Object.getTemplateKeywordLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getTemplateKeywordLoc")));

  Locs.insert(LocationAndString(Object.getLAngleLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getLAngleLoc")));

  Locs.insert(LocationAndString(Object.getRAngleLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getRAngleLoc")));

std::vector<clang::TypeLoc> TypeLocRecursionGuard;



              if (Object.getQualifierLoc())
                GetLocationsImpl(
                    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getQualifierLoc"),
                    Object.getQualifierLoc(), Locs, Rngs, TypeLocRecursionGuard);
              
                      GetLocationsImpl(
                          llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getNameInfo"),
                          Object.getNameInfo(), Locs, Rngs, TypeLocRecursionGuard);
                      }

static void GetLocationsDeclStmt(SharedLocationCall const& Prefix,
    clang::DeclStmt const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{
}

static void GetLocationsDeclarationNameInfo(SharedLocationCall const& Prefix,
    clang::DeclarationNameInfo const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs , std::vector<clang::TypeLoc>& TypeLocRecursionGuard)
{

  Locs.insert(LocationAndString(Object.getLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getLoc")));

  Locs.insert(LocationAndString(Object.getCXXLiteralOperatorNameLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getCXXLiteralOperatorNameLoc")));

  Locs.insert(LocationAndString(Object.getBeginLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getBeginLoc")));

  Locs.insert(LocationAndString(Object.getEndLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getEndLoc")));


  Rngs.insert(RangeAndString(Object.getCXXOperatorNameRange(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getCXXOperatorNameRange")));

  Rngs.insert(RangeAndString(Object.getSourceRange(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getSourceRange")));




              if (Object.getNamedTypeInfo()) {
                GetLocationsImpl(llvm::makeIntrusiveRefCnt<LocationCall>(
                    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getNamedTypeInfo",
                        LocationCall::ReturnsPointer), "getTypeLoc"),
                    Object.getNamedTypeInfo()->getTypeLoc(), Locs, Rngs, TypeLocRecursionGuard);
                    }
              
}

static void GetLocationsDeclaratorDecl(SharedLocationCall const& Prefix,
    clang::DeclaratorDecl const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{

  Locs.insert(LocationAndString(Object.getInnerLocStart(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getInnerLocStart")));

  Locs.insert(LocationAndString(Object.getOuterLocStart(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getOuterLocStart")));

  Locs.insert(LocationAndString(Object.getTypeSpecStartLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getTypeSpecStartLoc")));

  Locs.insert(LocationAndString(Object.getTypeSpecEndLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getTypeSpecEndLoc")));

std::vector<clang::TypeLoc> TypeLocRecursionGuard;



              if (Object.getTypeSourceInfo()) {
                GetLocationsImpl(llvm::makeIntrusiveRefCnt<LocationCall>(
                    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getTypeSourceInfo",
                        LocationCall::ReturnsPointer), "getTypeLoc"),
                    Object.getTypeSourceInfo()->getTypeLoc(), Locs, Rngs, TypeLocRecursionGuard);
                    }
              

              if (Object.getQualifierLoc())
                GetLocationsImpl(
                    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getQualifierLoc"),
                    Object.getQualifierLoc(), Locs, Rngs, TypeLocRecursionGuard);
              }

static void GetLocationsDecltypeTypeLoc(SharedLocationCall const& Prefix,
    clang::DecltypeTypeLoc const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs , std::vector<clang::TypeLoc>& TypeLocRecursionGuard)
{

  Locs.insert(LocationAndString(Object.getDecltypeLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getDecltypeLoc")));

  Locs.insert(LocationAndString(Object.getRParenLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getRParenLoc")));

}

static void GetLocationsDecompositionDecl(SharedLocationCall const& Prefix,
    clang::DecompositionDecl const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{
}

static void GetLocationsDeducedTemplateSpecializationTypeLoc(SharedLocationCall const& Prefix,
    clang::DeducedTemplateSpecializationTypeLoc const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs , std::vector<clang::TypeLoc>& TypeLocRecursionGuard)
{

  Locs.insert(LocationAndString(Object.getTemplateNameLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getTemplateNameLoc")));

}

static void GetLocationsDeducedTypeLoc(SharedLocationCall const& Prefix,
    clang::DeducedTypeLoc const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs , std::vector<clang::TypeLoc>& TypeLocRecursionGuard)
{
}

static void GetLocationsDefaultStmt(SharedLocationCall const& Prefix,
    clang::DefaultStmt const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{

  Locs.insert(LocationAndString(Object.getDefaultLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getDefaultLoc")));

}

static void GetLocationsDependentAddressSpaceTypeLoc(SharedLocationCall const& Prefix,
    clang::DependentAddressSpaceTypeLoc const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs , std::vector<clang::TypeLoc>& TypeLocRecursionGuard)
{

  Locs.insert(LocationAndString(Object.getAttrNameLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getAttrNameLoc")));


  Rngs.insert(RangeAndString(Object.getAttrOperandParensRange(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getAttrOperandParensRange")));



              if (Object.getPointeeTypeLoc()) {
                GetLocationsImpl(
                    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getPointeeTypeLoc"),
                    Object.getPointeeTypeLoc(), Locs, Rngs, TypeLocRecursionGuard);
                }
              
}

static void GetLocationsDependentBitIntTypeLoc(SharedLocationCall const& Prefix,
    clang::DependentBitIntTypeLoc const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs , std::vector<clang::TypeLoc>& TypeLocRecursionGuard)
{
}

static void GetLocationsDependentCoawaitExpr(SharedLocationCall const& Prefix,
    clang::DependentCoawaitExpr const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{

  Locs.insert(LocationAndString(Object.getKeywordLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getKeywordLoc")));

}

static void GetLocationsDependentNameTypeLoc(SharedLocationCall const& Prefix,
    clang::DependentNameTypeLoc const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs , std::vector<clang::TypeLoc>& TypeLocRecursionGuard)
{

  Locs.insert(LocationAndString(Object.getElaboratedKeywordLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getElaboratedKeywordLoc")));

  Locs.insert(LocationAndString(Object.getNameLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getNameLoc")));




              if (Object.getQualifierLoc())
                GetLocationsImpl(
                    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getQualifierLoc"),
                    Object.getQualifierLoc(), Locs, Rngs, TypeLocRecursionGuard);
              }

static void GetLocationsDependentScopeDeclRefExpr(SharedLocationCall const& Prefix,
    clang::DependentScopeDeclRefExpr const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{

  Locs.insert(LocationAndString(Object.getLocation(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getLocation")));

  Locs.insert(LocationAndString(Object.getTemplateKeywordLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getTemplateKeywordLoc")));

  Locs.insert(LocationAndString(Object.getLAngleLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getLAngleLoc")));

  Locs.insert(LocationAndString(Object.getRAngleLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getRAngleLoc")));

std::vector<clang::TypeLoc> TypeLocRecursionGuard;



              if (Object.getQualifierLoc())
                GetLocationsImpl(
                    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getQualifierLoc"),
                    Object.getQualifierLoc(), Locs, Rngs, TypeLocRecursionGuard);
              
                      GetLocationsImpl(
                          llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getNameInfo"),
                          Object.getNameInfo(), Locs, Rngs, TypeLocRecursionGuard);
                      }

static void GetLocationsDependentSizedArrayTypeLoc(SharedLocationCall const& Prefix,
    clang::DependentSizedArrayTypeLoc const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs , std::vector<clang::TypeLoc>& TypeLocRecursionGuard)
{
}

static void GetLocationsDependentSizedExtVectorTypeLoc(SharedLocationCall const& Prefix,
    clang::DependentSizedExtVectorTypeLoc const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs , std::vector<clang::TypeLoc>& TypeLocRecursionGuard)
{

  Locs.insert(LocationAndString(Object.getNameLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getNameLoc")));



              if (Object.getElementLoc()) {
                GetLocationsImpl(
                    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getElementLoc"),
                    Object.getElementLoc(), Locs, Rngs, TypeLocRecursionGuard);
                }
              
}

static void GetLocationsDependentSizedMatrixTypeLoc(SharedLocationCall const& Prefix,
    clang::DependentSizedMatrixTypeLoc const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs , std::vector<clang::TypeLoc>& TypeLocRecursionGuard)
{
}

static void GetLocationsDependentTemplateSpecializationTypeLoc(SharedLocationCall const& Prefix,
    clang::DependentTemplateSpecializationTypeLoc const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs , std::vector<clang::TypeLoc>& TypeLocRecursionGuard)
{

  Locs.insert(LocationAndString(Object.getElaboratedKeywordLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getElaboratedKeywordLoc")));

  Locs.insert(LocationAndString(Object.getTemplateKeywordLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getTemplateKeywordLoc")));

  Locs.insert(LocationAndString(Object.getTemplateNameLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getTemplateNameLoc")));

  Locs.insert(LocationAndString(Object.getLAngleLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getLAngleLoc")));

  Locs.insert(LocationAndString(Object.getRAngleLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getRAngleLoc")));




              if (Object.getQualifierLoc())
                GetLocationsImpl(
                    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getQualifierLoc"),
                    Object.getQualifierLoc(), Locs, Rngs, TypeLocRecursionGuard);
              }

static void GetLocationsDependentVectorTypeLoc(SharedLocationCall const& Prefix,
    clang::DependentVectorTypeLoc const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs , std::vector<clang::TypeLoc>& TypeLocRecursionGuard)
{

  Locs.insert(LocationAndString(Object.getNameLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getNameLoc")));



              if (Object.getElementLoc()) {
                GetLocationsImpl(
                    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getElementLoc"),
                    Object.getElementLoc(), Locs, Rngs, TypeLocRecursionGuard);
                }
              
}

static void GetLocationsDesignatedInitExpr(SharedLocationCall const& Prefix,
    clang::DesignatedInitExpr const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{

  Locs.insert(LocationAndString(Object.getEqualOrColonLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getEqualOrColonLoc")));


  Rngs.insert(RangeAndString(Object.getDesignatorsSourceRange(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getDesignatorsSourceRange")));

}

static void GetLocationsDesignatedInitUpdateExpr(SharedLocationCall const& Prefix,
    clang::DesignatedInitUpdateExpr const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{
}

static void GetLocationsDoStmt(SharedLocationCall const& Prefix,
    clang::DoStmt const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{

  Locs.insert(LocationAndString(Object.getDoLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getDoLoc")));

  Locs.insert(LocationAndString(Object.getWhileLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getWhileLoc")));

  Locs.insert(LocationAndString(Object.getRParenLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getRParenLoc")));

}

static void GetLocationsElaboratedTypeLoc(SharedLocationCall const& Prefix,
    clang::ElaboratedTypeLoc const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs , std::vector<clang::TypeLoc>& TypeLocRecursionGuard)
{

  Locs.insert(LocationAndString(Object.getElaboratedKeywordLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getElaboratedKeywordLoc")));



              if (Object.getNamedTypeLoc()) {
                GetLocationsImpl(
                    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getNamedTypeLoc"),
                    Object.getNamedTypeLoc(), Locs, Rngs, TypeLocRecursionGuard);
                }
              

              if (Object.getQualifierLoc())
                GetLocationsImpl(
                    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getQualifierLoc"),
                    Object.getQualifierLoc(), Locs, Rngs, TypeLocRecursionGuard);
              }

static void GetLocationsEmptyDecl(SharedLocationCall const& Prefix,
    clang::EmptyDecl const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{
}

static void GetLocationsEnumConstantDecl(SharedLocationCall const& Prefix,
    clang::EnumConstantDecl const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{
}

static void GetLocationsEnumDecl(SharedLocationCall const& Prefix,
    clang::EnumDecl const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{

  Rngs.insert(RangeAndString(Object.getIntegerTypeRange(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getIntegerTypeRange")));

std::vector<clang::TypeLoc> TypeLocRecursionGuard;



              if (Object.getIntegerTypeSourceInfo()) {
                GetLocationsImpl(llvm::makeIntrusiveRefCnt<LocationCall>(
                    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getIntegerTypeSourceInfo",
                        LocationCall::ReturnsPointer), "getTypeLoc"),
                    Object.getIntegerTypeSourceInfo()->getTypeLoc(), Locs, Rngs, TypeLocRecursionGuard);
                    }
              
}

static void GetLocationsEnumTypeLoc(SharedLocationCall const& Prefix,
    clang::EnumTypeLoc const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs , std::vector<clang::TypeLoc>& TypeLocRecursionGuard)
{
}

static void GetLocationsExplicitCastExpr(SharedLocationCall const& Prefix,
    clang::ExplicitCastExpr const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{
std::vector<clang::TypeLoc> TypeLocRecursionGuard;



              if (Object.getTypeInfoAsWritten()) {
                GetLocationsImpl(llvm::makeIntrusiveRefCnt<LocationCall>(
                    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getTypeInfoAsWritten",
                        LocationCall::ReturnsPointer), "getTypeLoc"),
                    Object.getTypeInfoAsWritten()->getTypeLoc(), Locs, Rngs, TypeLocRecursionGuard);
                    }
              
}

static void GetLocationsExportDecl(SharedLocationCall const& Prefix,
    clang::ExportDecl const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{

  Locs.insert(LocationAndString(Object.getExportLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getExportLoc")));

  Locs.insert(LocationAndString(Object.getRBraceLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getRBraceLoc")));

}

static void GetLocationsExpr(SharedLocationCall const& Prefix,
    clang::Expr const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{

  Locs.insert(LocationAndString(Object.getExprLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getExprLoc")));

}

static void GetLocationsExprWithCleanups(SharedLocationCall const& Prefix,
    clang::ExprWithCleanups const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{
}

static void GetLocationsExpressionTraitExpr(SharedLocationCall const& Prefix,
    clang::ExpressionTraitExpr const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{
}

static void GetLocationsExtVectorElementExpr(SharedLocationCall const& Prefix,
    clang::ExtVectorElementExpr const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{

  Locs.insert(LocationAndString(Object.getAccessorLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getAccessorLoc")));

}

static void GetLocationsExtVectorTypeLoc(SharedLocationCall const& Prefix,
    clang::ExtVectorTypeLoc const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs , std::vector<clang::TypeLoc>& TypeLocRecursionGuard)
{
}

static void GetLocationsExternCContextDecl(SharedLocationCall const& Prefix,
    clang::ExternCContextDecl const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{
}

static void GetLocationsFieldDecl(SharedLocationCall const& Prefix,
    clang::FieldDecl const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{
}

static void GetLocationsFileScopeAsmDecl(SharedLocationCall const& Prefix,
    clang::FileScopeAsmDecl const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{

  Locs.insert(LocationAndString(Object.getAsmLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getAsmLoc")));

  Locs.insert(LocationAndString(Object.getRParenLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getRParenLoc")));

}

static void GetLocationsFixedPointLiteral(SharedLocationCall const& Prefix,
    clang::FixedPointLiteral const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{

  Locs.insert(LocationAndString(Object.getLocation(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getLocation")));

}

static void GetLocationsFloatingLiteral(SharedLocationCall const& Prefix,
    clang::FloatingLiteral const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{

  Locs.insert(LocationAndString(Object.getLocation(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getLocation")));

}

static void GetLocationsForStmt(SharedLocationCall const& Prefix,
    clang::ForStmt const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{

  Locs.insert(LocationAndString(Object.getForLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getForLoc")));

  Locs.insert(LocationAndString(Object.getLParenLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getLParenLoc")));

  Locs.insert(LocationAndString(Object.getRParenLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getRParenLoc")));

}

static void GetLocationsFriendTemplateDecl(SharedLocationCall const& Prefix,
    clang::FriendTemplateDecl const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{

  Locs.insert(LocationAndString(Object.getFriendLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getFriendLoc")));

std::vector<clang::TypeLoc> TypeLocRecursionGuard;



              if (Object.getFriendType()) {
                GetLocationsImpl(llvm::makeIntrusiveRefCnt<LocationCall>(
                    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getFriendType",
                        LocationCall::ReturnsPointer), "getTypeLoc"),
                    Object.getFriendType()->getTypeLoc(), Locs, Rngs, TypeLocRecursionGuard);
                    }
              
}

static void GetLocationsFullExpr(SharedLocationCall const& Prefix,
    clang::FullExpr const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{
}

static void GetLocationsFunctionDecl(SharedLocationCall const& Prefix,
    clang::FunctionDecl const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{

  Locs.insert(LocationAndString(Object.getEllipsisLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getEllipsisLoc")));

  Locs.insert(LocationAndString(Object.getPointOfInstantiation(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getPointOfInstantiation")));


  Rngs.insert(RangeAndString(Object.getReturnTypeSourceRange(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getReturnTypeSourceRange")));

  Rngs.insert(RangeAndString(Object.getParametersSourceRange(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getParametersSourceRange")));

  Rngs.insert(RangeAndString(Object.getExceptionSpecSourceRange(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getExceptionSpecSourceRange")));

std::vector<clang::TypeLoc> TypeLocRecursionGuard;



                      GetLocationsImpl(
                          llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getNameInfo"),
                          Object.getNameInfo(), Locs, Rngs, TypeLocRecursionGuard);
                      }

static void GetLocationsFunctionNoProtoTypeLoc(SharedLocationCall const& Prefix,
    clang::FunctionNoProtoTypeLoc const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs , std::vector<clang::TypeLoc>& TypeLocRecursionGuard)
{
}

static void GetLocationsFunctionParmPackExpr(SharedLocationCall const& Prefix,
    clang::FunctionParmPackExpr const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{

  Locs.insert(LocationAndString(Object.getParameterPackLocation(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getParameterPackLocation")));

}

static void GetLocationsFunctionProtoTypeLoc(SharedLocationCall const& Prefix,
    clang::FunctionProtoTypeLoc const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs , std::vector<clang::TypeLoc>& TypeLocRecursionGuard)
{
}

static void GetLocationsFunctionTemplateDecl(SharedLocationCall const& Prefix,
    clang::FunctionTemplateDecl const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{
}

static void GetLocationsFunctionTypeLoc(SharedLocationCall const& Prefix,
    clang::FunctionTypeLoc const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs , std::vector<clang::TypeLoc>& TypeLocRecursionGuard)
{

  Locs.insert(LocationAndString(Object.getLocalRangeBegin(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getLocalRangeBegin")));

  Locs.insert(LocationAndString(Object.getLocalRangeEnd(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getLocalRangeEnd")));

  Locs.insert(LocationAndString(Object.getLParenLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getLParenLoc")));

  Locs.insert(LocationAndString(Object.getRParenLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getRParenLoc")));


  Rngs.insert(RangeAndString(Object.getParensRange(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getParensRange")));

  Rngs.insert(RangeAndString(Object.getExceptionSpecRange(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getExceptionSpecRange")));



              if (Object.getReturnLoc()) {
                GetLocationsImpl(
                    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getReturnLoc"),
                    Object.getReturnLoc(), Locs, Rngs, TypeLocRecursionGuard);
                }
              
}

static void GetLocationsGCCAsmStmt(SharedLocationCall const& Prefix,
    clang::GCCAsmStmt const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{

  Locs.insert(LocationAndString(Object.getRParenLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getRParenLoc")));

}

static void GetLocationsGNUNullExpr(SharedLocationCall const& Prefix,
    clang::GNUNullExpr const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{

  Locs.insert(LocationAndString(Object.getTokenLocation(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getTokenLocation")));

}

static void GetLocationsGenericSelectionExpr(SharedLocationCall const& Prefix,
    clang::GenericSelectionExpr const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{

  Locs.insert(LocationAndString(Object.getGenericLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getGenericLoc")));

  Locs.insert(LocationAndString(Object.getDefaultLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getDefaultLoc")));

  Locs.insert(LocationAndString(Object.getRParenLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getRParenLoc")));

}

static void GetLocationsGotoStmt(SharedLocationCall const& Prefix,
    clang::GotoStmt const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{

  Locs.insert(LocationAndString(Object.getGotoLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getGotoLoc")));

  Locs.insert(LocationAndString(Object.getLabelLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getLabelLoc")));

}

static void GetLocationsIfStmt(SharedLocationCall const& Prefix,
    clang::IfStmt const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{

  Locs.insert(LocationAndString(Object.getIfLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getIfLoc")));

  Locs.insert(LocationAndString(Object.getElseLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getElseLoc")));

  Locs.insert(LocationAndString(Object.getLParenLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getLParenLoc")));

  Locs.insert(LocationAndString(Object.getRParenLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getRParenLoc")));

}

static void GetLocationsImaginaryLiteral(SharedLocationCall const& Prefix,
    clang::ImaginaryLiteral const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{
}

static void GetLocationsImplicitCastExpr(SharedLocationCall const& Prefix,
    clang::ImplicitCastExpr const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{
}

static void GetLocationsImplicitParamDecl(SharedLocationCall const& Prefix,
    clang::ImplicitParamDecl const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{
}

static void GetLocationsImplicitValueInitExpr(SharedLocationCall const& Prefix,
    clang::ImplicitValueInitExpr const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{
}

static void GetLocationsImportDecl(SharedLocationCall const& Prefix,
    clang::ImportDecl const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{
}

static void GetLocationsIncompleteArrayTypeLoc(SharedLocationCall const& Prefix,
    clang::IncompleteArrayTypeLoc const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs , std::vector<clang::TypeLoc>& TypeLocRecursionGuard)
{
}

static void GetLocationsIndirectFieldDecl(SharedLocationCall const& Prefix,
    clang::IndirectFieldDecl const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{
}

static void GetLocationsIndirectGotoStmt(SharedLocationCall const& Prefix,
    clang::IndirectGotoStmt const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{

  Locs.insert(LocationAndString(Object.getGotoLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getGotoLoc")));

  Locs.insert(LocationAndString(Object.getStarLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getStarLoc")));

}

static void GetLocationsInitListExpr(SharedLocationCall const& Prefix,
    clang::InitListExpr const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{

  Locs.insert(LocationAndString(Object.getLBraceLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getLBraceLoc")));

  Locs.insert(LocationAndString(Object.getRBraceLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getRBraceLoc")));

}

static void GetLocationsInjectedClassNameTypeLoc(SharedLocationCall const& Prefix,
    clang::InjectedClassNameTypeLoc const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs , std::vector<clang::TypeLoc>& TypeLocRecursionGuard)
{
}

static void GetLocationsIntegerLiteral(SharedLocationCall const& Prefix,
    clang::IntegerLiteral const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{

  Locs.insert(LocationAndString(Object.getLocation(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getLocation")));

}

static void GetLocationsLValueReferenceTypeLoc(SharedLocationCall const& Prefix,
    clang::LValueReferenceTypeLoc const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs , std::vector<clang::TypeLoc>& TypeLocRecursionGuard)
{

  Locs.insert(LocationAndString(Object.getAmpLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getAmpLoc")));

}

static void GetLocationsLabelDecl(SharedLocationCall const& Prefix,
    clang::LabelDecl const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{
}

static void GetLocationsLabelStmt(SharedLocationCall const& Prefix,
    clang::LabelStmt const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{

  Locs.insert(LocationAndString(Object.getIdentLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getIdentLoc")));

}

static void GetLocationsLambdaExpr(SharedLocationCall const& Prefix,
    clang::LambdaExpr const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{

  Locs.insert(LocationAndString(Object.getCaptureDefaultLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getCaptureDefaultLoc")));


  Rngs.insert(RangeAndString(Object.getIntroducerRange(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getIntroducerRange")));

}

static void GetLocationsLifetimeExtendedTemporaryDecl(SharedLocationCall const& Prefix,
    clang::LifetimeExtendedTemporaryDecl const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{
}

static void GetLocationsLinkageSpecDecl(SharedLocationCall const& Prefix,
    clang::LinkageSpecDecl const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{

  Locs.insert(LocationAndString(Object.getExternLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getExternLoc")));

  Locs.insert(LocationAndString(Object.getRBraceLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getRBraceLoc")));

}

static void GetLocationsMSAsmStmt(SharedLocationCall const& Prefix,
    clang::MSAsmStmt const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{

  Locs.insert(LocationAndString(Object.getLBraceLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getLBraceLoc")));

}

static void GetLocationsMSDependentExistsStmt(SharedLocationCall const& Prefix,
    clang::MSDependentExistsStmt const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{

  Locs.insert(LocationAndString(Object.getKeywordLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getKeywordLoc")));

std::vector<clang::TypeLoc> TypeLocRecursionGuard;



              if (Object.getQualifierLoc())
                GetLocationsImpl(
                    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getQualifierLoc"),
                    Object.getQualifierLoc(), Locs, Rngs, TypeLocRecursionGuard);
              
                      GetLocationsImpl(
                          llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getNameInfo"),
                          Object.getNameInfo(), Locs, Rngs, TypeLocRecursionGuard);
                      }

static void GetLocationsMSGuidDecl(SharedLocationCall const& Prefix,
    clang::MSGuidDecl const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{
}

static void GetLocationsMSPropertyDecl(SharedLocationCall const& Prefix,
    clang::MSPropertyDecl const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{
}

static void GetLocationsMSPropertyRefExpr(SharedLocationCall const& Prefix,
    clang::MSPropertyRefExpr const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{

  Locs.insert(LocationAndString(Object.getMemberLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getMemberLoc")));

std::vector<clang::TypeLoc> TypeLocRecursionGuard;



              if (Object.getQualifierLoc())
                GetLocationsImpl(
                    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getQualifierLoc"),
                    Object.getQualifierLoc(), Locs, Rngs, TypeLocRecursionGuard);
              }

static void GetLocationsMSPropertySubscriptExpr(SharedLocationCall const& Prefix,
    clang::MSPropertySubscriptExpr const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{

  Locs.insert(LocationAndString(Object.getRBracketLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getRBracketLoc")));

}

static void GetLocationsMacroQualifiedTypeLoc(SharedLocationCall const& Prefix,
    clang::MacroQualifiedTypeLoc const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs , std::vector<clang::TypeLoc>& TypeLocRecursionGuard)
{

  Locs.insert(LocationAndString(Object.getExpansionLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getExpansionLoc")));



              if (Object.getInnerLoc()) {
                GetLocationsImpl(
                    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getInnerLoc"),
                    Object.getInnerLoc(), Locs, Rngs, TypeLocRecursionGuard);
                }
              
}

static void GetLocationsMaterializeTemporaryExpr(SharedLocationCall const& Prefix,
    clang::MaterializeTemporaryExpr const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{
}

static void GetLocationsMatrixSubscriptExpr(SharedLocationCall const& Prefix,
    clang::MatrixSubscriptExpr const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{

  Locs.insert(LocationAndString(Object.getRBracketLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getRBracketLoc")));

}

static void GetLocationsMatrixTypeLoc(SharedLocationCall const& Prefix,
    clang::MatrixTypeLoc const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs , std::vector<clang::TypeLoc>& TypeLocRecursionGuard)
{

  Locs.insert(LocationAndString(Object.getAttrNameLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getAttrNameLoc")));


  Rngs.insert(RangeAndString(Object.getAttrOperandParensRange(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getAttrOperandParensRange")));

}

static void GetLocationsMemberExpr(SharedLocationCall const& Prefix,
    clang::MemberExpr const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{

  Locs.insert(LocationAndString(Object.getTemplateKeywordLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getTemplateKeywordLoc")));

  Locs.insert(LocationAndString(Object.getLAngleLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getLAngleLoc")));

  Locs.insert(LocationAndString(Object.getRAngleLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getRAngleLoc")));

  Locs.insert(LocationAndString(Object.getOperatorLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getOperatorLoc")));

  Locs.insert(LocationAndString(Object.getMemberLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getMemberLoc")));

std::vector<clang::TypeLoc> TypeLocRecursionGuard;



              if (Object.getQualifierLoc())
                GetLocationsImpl(
                    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getQualifierLoc"),
                    Object.getQualifierLoc(), Locs, Rngs, TypeLocRecursionGuard);
              
                      GetLocationsImpl(
                          llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getMemberNameInfo"),
                          Object.getMemberNameInfo(), Locs, Rngs, TypeLocRecursionGuard);
                      }

static void GetLocationsMemberPointerTypeLoc(SharedLocationCall const& Prefix,
    clang::MemberPointerTypeLoc const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs , std::vector<clang::TypeLoc>& TypeLocRecursionGuard)
{

  Locs.insert(LocationAndString(Object.getStarLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getStarLoc")));




              if (Object.getClassTInfo()) {
                GetLocationsImpl(llvm::makeIntrusiveRefCnt<LocationCall>(
                    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getClassTInfo",
                        LocationCall::ReturnsPointer), "getTypeLoc"),
                    Object.getClassTInfo()->getTypeLoc(), Locs, Rngs, TypeLocRecursionGuard);
                    }
              
}

static void GetLocationsNamedDecl(SharedLocationCall const& Prefix,
    clang::NamedDecl const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{
}

static void GetLocationsNamespaceAliasDecl(SharedLocationCall const& Prefix,
    clang::NamespaceAliasDecl const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{

  Locs.insert(LocationAndString(Object.getAliasLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getAliasLoc")));

  Locs.insert(LocationAndString(Object.getNamespaceLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getNamespaceLoc")));

  Locs.insert(LocationAndString(Object.getTargetNameLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getTargetNameLoc")));

std::vector<clang::TypeLoc> TypeLocRecursionGuard;



              if (Object.getQualifierLoc())
                GetLocationsImpl(
                    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getQualifierLoc"),
                    Object.getQualifierLoc(), Locs, Rngs, TypeLocRecursionGuard);
              }

static void GetLocationsNamespaceDecl(SharedLocationCall const& Prefix,
    clang::NamespaceDecl const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{

  Locs.insert(LocationAndString(Object.getRBraceLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getRBraceLoc")));

}

static void GetLocationsNestedNameSpecifierLoc(SharedLocationCall const& Prefix,
    clang::NestedNameSpecifierLoc const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs , std::vector<clang::TypeLoc>& TypeLocRecursionGuard)
{

  Locs.insert(LocationAndString(Object.getBeginLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getBeginLoc")));

  Locs.insert(LocationAndString(Object.getEndLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getEndLoc")));

  Locs.insert(LocationAndString(Object.getLocalBeginLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getLocalBeginLoc")));

  Locs.insert(LocationAndString(Object.getLocalEndLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getLocalEndLoc")));


  Rngs.insert(RangeAndString(Object.getSourceRange(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getSourceRange")));

  Rngs.insert(RangeAndString(Object.getLocalSourceRange(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getLocalSourceRange")));



              if (Object.getTypeLoc()) {
                GetLocationsImpl(
                    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getTypeLoc"),
                    Object.getTypeLoc(), Locs, Rngs, TypeLocRecursionGuard);
                }
              

              if (Object.getPrefix())
                GetLocationsImpl(
                    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getPrefix"),
                    Object.getPrefix(), Locs, Rngs, TypeLocRecursionGuard);
              }

static void GetLocationsNoInitExpr(SharedLocationCall const& Prefix,
    clang::NoInitExpr const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{
}

static void GetLocationsNonTypeTemplateParmDecl(SharedLocationCall const& Prefix,
    clang::NonTypeTemplateParmDecl const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{

  Locs.insert(LocationAndString(Object.getDefaultArgumentLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getDefaultArgumentLoc")));

}

static void GetLocationsNullStmt(SharedLocationCall const& Prefix,
    clang::NullStmt const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{

  Locs.insert(LocationAndString(Object.getSemiLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getSemiLoc")));

}

static void GetLocationsOMPArraySectionExpr(SharedLocationCall const& Prefix,
    clang::OMPArraySectionExpr const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{

  Locs.insert(LocationAndString(Object.getColonLocFirst(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getColonLocFirst")));

  Locs.insert(LocationAndString(Object.getColonLocSecond(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getColonLocSecond")));

  Locs.insert(LocationAndString(Object.getRBracketLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getRBracketLoc")));

}

static void GetLocationsOMPArrayShapingExpr(SharedLocationCall const& Prefix,
    clang::OMPArrayShapingExpr const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{

  Locs.insert(LocationAndString(Object.getLParenLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getLParenLoc")));

  Locs.insert(LocationAndString(Object.getRParenLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getRParenLoc")));

}

static void GetLocationsOMPAtomicDirective(SharedLocationCall const& Prefix,
    clang::OMPAtomicDirective const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{
}

static void GetLocationsOMPBarrierDirective(SharedLocationCall const& Prefix,
    clang::OMPBarrierDirective const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{
}

static void GetLocationsOMPCancelDirective(SharedLocationCall const& Prefix,
    clang::OMPCancelDirective const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{
}

static void GetLocationsOMPCancellationPointDirective(SharedLocationCall const& Prefix,
    clang::OMPCancellationPointDirective const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{
}

static void GetLocationsOMPCanonicalLoop(SharedLocationCall const& Prefix,
    clang::OMPCanonicalLoop const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{
}

static void GetLocationsOMPCriticalDirective(SharedLocationCall const& Prefix,
    clang::OMPCriticalDirective const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{
std::vector<clang::TypeLoc> TypeLocRecursionGuard;



                      GetLocationsImpl(
                          llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getDirectiveName"),
                          Object.getDirectiveName(), Locs, Rngs, TypeLocRecursionGuard);
                      }

static void GetLocationsOMPDepobjDirective(SharedLocationCall const& Prefix,
    clang::OMPDepobjDirective const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{
}

static void GetLocationsOMPDispatchDirective(SharedLocationCall const& Prefix,
    clang::OMPDispatchDirective const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{

  Locs.insert(LocationAndString(Object.getTargetCallLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getTargetCallLoc")));

}

static void GetLocationsOMPDistributeDirective(SharedLocationCall const& Prefix,
    clang::OMPDistributeDirective const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{
}

static void GetLocationsOMPDistributeParallelForDirective(SharedLocationCall const& Prefix,
    clang::OMPDistributeParallelForDirective const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{
}

static void GetLocationsOMPDistributeParallelForSimdDirective(SharedLocationCall const& Prefix,
    clang::OMPDistributeParallelForSimdDirective const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{
}

static void GetLocationsOMPDistributeSimdDirective(SharedLocationCall const& Prefix,
    clang::OMPDistributeSimdDirective const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{
}

static void GetLocationsOMPExecutableDirective(SharedLocationCall const& Prefix,
    clang::OMPExecutableDirective const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{
}

static void GetLocationsOMPFlushDirective(SharedLocationCall const& Prefix,
    clang::OMPFlushDirective const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{
}

static void GetLocationsOMPForDirective(SharedLocationCall const& Prefix,
    clang::OMPForDirective const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{
}

static void GetLocationsOMPForSimdDirective(SharedLocationCall const& Prefix,
    clang::OMPForSimdDirective const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{
}

static void GetLocationsOMPGenericLoopDirective(SharedLocationCall const& Prefix,
    clang::OMPGenericLoopDirective const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{
}

static void GetLocationsOMPInteropDirective(SharedLocationCall const& Prefix,
    clang::OMPInteropDirective const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{
}

static void GetLocationsOMPIteratorExpr(SharedLocationCall const& Prefix,
    clang::OMPIteratorExpr const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{

  Locs.insert(LocationAndString(Object.getLParenLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getLParenLoc")));

  Locs.insert(LocationAndString(Object.getRParenLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getRParenLoc")));

  Locs.insert(LocationAndString(Object.getIteratorKwLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getIteratorKwLoc")));

}

static void GetLocationsOMPLoopBasedDirective(SharedLocationCall const& Prefix,
    clang::OMPLoopBasedDirective const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{
}

static void GetLocationsOMPLoopDirective(SharedLocationCall const& Prefix,
    clang::OMPLoopDirective const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{
}

static void GetLocationsOMPLoopTransformationDirective(SharedLocationCall const& Prefix,
    clang::OMPLoopTransformationDirective const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{
}

static void GetLocationsOMPMaskedDirective(SharedLocationCall const& Prefix,
    clang::OMPMaskedDirective const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{
}

static void GetLocationsOMPMasterDirective(SharedLocationCall const& Prefix,
    clang::OMPMasterDirective const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{
}

static void GetLocationsOMPMasterTaskLoopDirective(SharedLocationCall const& Prefix,
    clang::OMPMasterTaskLoopDirective const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{
}

static void GetLocationsOMPMasterTaskLoopSimdDirective(SharedLocationCall const& Prefix,
    clang::OMPMasterTaskLoopSimdDirective const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{
}

static void GetLocationsOMPMetaDirective(SharedLocationCall const& Prefix,
    clang::OMPMetaDirective const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{
}

static void GetLocationsOMPOrderedDirective(SharedLocationCall const& Prefix,
    clang::OMPOrderedDirective const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{
}

static void GetLocationsOMPParallelDirective(SharedLocationCall const& Prefix,
    clang::OMPParallelDirective const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{
}

static void GetLocationsOMPParallelForDirective(SharedLocationCall const& Prefix,
    clang::OMPParallelForDirective const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{
}

static void GetLocationsOMPParallelForSimdDirective(SharedLocationCall const& Prefix,
    clang::OMPParallelForSimdDirective const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{
}

static void GetLocationsOMPParallelMasterDirective(SharedLocationCall const& Prefix,
    clang::OMPParallelMasterDirective const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{
}

static void GetLocationsOMPParallelMasterTaskLoopDirective(SharedLocationCall const& Prefix,
    clang::OMPParallelMasterTaskLoopDirective const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{
}

static void GetLocationsOMPParallelMasterTaskLoopSimdDirective(SharedLocationCall const& Prefix,
    clang::OMPParallelMasterTaskLoopSimdDirective const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{
}

static void GetLocationsOMPParallelSectionsDirective(SharedLocationCall const& Prefix,
    clang::OMPParallelSectionsDirective const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{
}

static void GetLocationsOMPScanDirective(SharedLocationCall const& Prefix,
    clang::OMPScanDirective const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{
}

static void GetLocationsOMPSectionDirective(SharedLocationCall const& Prefix,
    clang::OMPSectionDirective const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{
}

static void GetLocationsOMPSectionsDirective(SharedLocationCall const& Prefix,
    clang::OMPSectionsDirective const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{
}

static void GetLocationsOMPSimdDirective(SharedLocationCall const& Prefix,
    clang::OMPSimdDirective const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{
}

static void GetLocationsOMPSingleDirective(SharedLocationCall const& Prefix,
    clang::OMPSingleDirective const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{
}

static void GetLocationsOMPTargetDataDirective(SharedLocationCall const& Prefix,
    clang::OMPTargetDataDirective const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{
}

static void GetLocationsOMPTargetDirective(SharedLocationCall const& Prefix,
    clang::OMPTargetDirective const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{
}

static void GetLocationsOMPTargetEnterDataDirective(SharedLocationCall const& Prefix,
    clang::OMPTargetEnterDataDirective const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{
}

static void GetLocationsOMPTargetExitDataDirective(SharedLocationCall const& Prefix,
    clang::OMPTargetExitDataDirective const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{
}

static void GetLocationsOMPTargetParallelDirective(SharedLocationCall const& Prefix,
    clang::OMPTargetParallelDirective const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{
}

static void GetLocationsOMPTargetParallelForDirective(SharedLocationCall const& Prefix,
    clang::OMPTargetParallelForDirective const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{
}

static void GetLocationsOMPTargetParallelForSimdDirective(SharedLocationCall const& Prefix,
    clang::OMPTargetParallelForSimdDirective const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{
}

static void GetLocationsOMPTargetSimdDirective(SharedLocationCall const& Prefix,
    clang::OMPTargetSimdDirective const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{
}

static void GetLocationsOMPTargetTeamsDirective(SharedLocationCall const& Prefix,
    clang::OMPTargetTeamsDirective const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{
}

static void GetLocationsOMPTargetTeamsDistributeDirective(SharedLocationCall const& Prefix,
    clang::OMPTargetTeamsDistributeDirective const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{
}

static void GetLocationsOMPTargetTeamsDistributeParallelForDirective(SharedLocationCall const& Prefix,
    clang::OMPTargetTeamsDistributeParallelForDirective const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{
}

static void GetLocationsOMPTargetTeamsDistributeParallelForSimdDirective(SharedLocationCall const& Prefix,
    clang::OMPTargetTeamsDistributeParallelForSimdDirective const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{
}

static void GetLocationsOMPTargetTeamsDistributeSimdDirective(SharedLocationCall const& Prefix,
    clang::OMPTargetTeamsDistributeSimdDirective const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{
}

static void GetLocationsOMPTargetUpdateDirective(SharedLocationCall const& Prefix,
    clang::OMPTargetUpdateDirective const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{
}

static void GetLocationsOMPTaskDirective(SharedLocationCall const& Prefix,
    clang::OMPTaskDirective const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{
}

static void GetLocationsOMPTaskLoopDirective(SharedLocationCall const& Prefix,
    clang::OMPTaskLoopDirective const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{
}

static void GetLocationsOMPTaskLoopSimdDirective(SharedLocationCall const& Prefix,
    clang::OMPTaskLoopSimdDirective const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{
}

static void GetLocationsOMPTaskgroupDirective(SharedLocationCall const& Prefix,
    clang::OMPTaskgroupDirective const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{
}

static void GetLocationsOMPTaskwaitDirective(SharedLocationCall const& Prefix,
    clang::OMPTaskwaitDirective const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{
}

static void GetLocationsOMPTaskyieldDirective(SharedLocationCall const& Prefix,
    clang::OMPTaskyieldDirective const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{
}

static void GetLocationsOMPTeamsDirective(SharedLocationCall const& Prefix,
    clang::OMPTeamsDirective const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{
}

static void GetLocationsOMPTeamsDistributeDirective(SharedLocationCall const& Prefix,
    clang::OMPTeamsDistributeDirective const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{
}

static void GetLocationsOMPTeamsDistributeParallelForDirective(SharedLocationCall const& Prefix,
    clang::OMPTeamsDistributeParallelForDirective const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{
}

static void GetLocationsOMPTeamsDistributeParallelForSimdDirective(SharedLocationCall const& Prefix,
    clang::OMPTeamsDistributeParallelForSimdDirective const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{
}

static void GetLocationsOMPTeamsDistributeSimdDirective(SharedLocationCall const& Prefix,
    clang::OMPTeamsDistributeSimdDirective const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{
}

static void GetLocationsOMPTileDirective(SharedLocationCall const& Prefix,
    clang::OMPTileDirective const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{
}

static void GetLocationsOMPUnrollDirective(SharedLocationCall const& Prefix,
    clang::OMPUnrollDirective const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{
}

static void GetLocationsObjCArrayLiteral(SharedLocationCall const& Prefix,
    clang::ObjCArrayLiteral const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{
}

static void GetLocationsObjCAtCatchStmt(SharedLocationCall const& Prefix,
    clang::ObjCAtCatchStmt const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{

  Locs.insert(LocationAndString(Object.getAtCatchLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getAtCatchLoc")));

  Locs.insert(LocationAndString(Object.getRParenLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getRParenLoc")));

}

static void GetLocationsObjCAtDefsFieldDecl(SharedLocationCall const& Prefix,
    clang::ObjCAtDefsFieldDecl const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{
}

static void GetLocationsObjCAtFinallyStmt(SharedLocationCall const& Prefix,
    clang::ObjCAtFinallyStmt const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{

  Locs.insert(LocationAndString(Object.getAtFinallyLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getAtFinallyLoc")));

}

static void GetLocationsObjCAtSynchronizedStmt(SharedLocationCall const& Prefix,
    clang::ObjCAtSynchronizedStmt const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{

  Locs.insert(LocationAndString(Object.getAtSynchronizedLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getAtSynchronizedLoc")));

}

static void GetLocationsObjCAtThrowStmt(SharedLocationCall const& Prefix,
    clang::ObjCAtThrowStmt const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{

  Locs.insert(LocationAndString(Object.getThrowLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getThrowLoc")));

}

static void GetLocationsObjCAtTryStmt(SharedLocationCall const& Prefix,
    clang::ObjCAtTryStmt const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{

  Locs.insert(LocationAndString(Object.getAtTryLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getAtTryLoc")));

}

static void GetLocationsObjCAutoreleasePoolStmt(SharedLocationCall const& Prefix,
    clang::ObjCAutoreleasePoolStmt const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{

  Locs.insert(LocationAndString(Object.getAtLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getAtLoc")));

}

static void GetLocationsObjCAvailabilityCheckExpr(SharedLocationCall const& Prefix,
    clang::ObjCAvailabilityCheckExpr const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{
}

static void GetLocationsObjCBoolLiteralExpr(SharedLocationCall const& Prefix,
    clang::ObjCBoolLiteralExpr const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{

  Locs.insert(LocationAndString(Object.getLocation(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getLocation")));

}

static void GetLocationsObjCBoxedExpr(SharedLocationCall const& Prefix,
    clang::ObjCBoxedExpr const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{

  Locs.insert(LocationAndString(Object.getAtLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getAtLoc")));

}

static void GetLocationsObjCBridgedCastExpr(SharedLocationCall const& Prefix,
    clang::ObjCBridgedCastExpr const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{

  Locs.insert(LocationAndString(Object.getLParenLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getLParenLoc")));

  Locs.insert(LocationAndString(Object.getBridgeKeywordLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getBridgeKeywordLoc")));

}

static void GetLocationsObjCCategoryDecl(SharedLocationCall const& Prefix,
    clang::ObjCCategoryDecl const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{

  Locs.insert(LocationAndString(Object.getCategoryNameLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getCategoryNameLoc")));

  Locs.insert(LocationAndString(Object.getIvarLBraceLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getIvarLBraceLoc")));

  Locs.insert(LocationAndString(Object.getIvarRBraceLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getIvarRBraceLoc")));

}

static void GetLocationsObjCCategoryImplDecl(SharedLocationCall const& Prefix,
    clang::ObjCCategoryImplDecl const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{

  Locs.insert(LocationAndString(Object.getCategoryNameLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getCategoryNameLoc")));

}

static void GetLocationsObjCCompatibleAliasDecl(SharedLocationCall const& Prefix,
    clang::ObjCCompatibleAliasDecl const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{
}

static void GetLocationsObjCContainerDecl(SharedLocationCall const& Prefix,
    clang::ObjCContainerDecl const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{

  Locs.insert(LocationAndString(Object.getAtStartLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getAtStartLoc")));


  Rngs.insert(RangeAndString(Object.getAtEndRange(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getAtEndRange")));

}

static void GetLocationsObjCDictionaryLiteral(SharedLocationCall const& Prefix,
    clang::ObjCDictionaryLiteral const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{
}

static void GetLocationsObjCEncodeExpr(SharedLocationCall const& Prefix,
    clang::ObjCEncodeExpr const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{

  Locs.insert(LocationAndString(Object.getAtLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getAtLoc")));

  Locs.insert(LocationAndString(Object.getRParenLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getRParenLoc")));

std::vector<clang::TypeLoc> TypeLocRecursionGuard;



              if (Object.getEncodedTypeSourceInfo()) {
                GetLocationsImpl(llvm::makeIntrusiveRefCnt<LocationCall>(
                    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getEncodedTypeSourceInfo",
                        LocationCall::ReturnsPointer), "getTypeLoc"),
                    Object.getEncodedTypeSourceInfo()->getTypeLoc(), Locs, Rngs, TypeLocRecursionGuard);
                    }
              
}

static void GetLocationsObjCForCollectionStmt(SharedLocationCall const& Prefix,
    clang::ObjCForCollectionStmt const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{

  Locs.insert(LocationAndString(Object.getForLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getForLoc")));

  Locs.insert(LocationAndString(Object.getRParenLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getRParenLoc")));

}

static void GetLocationsObjCImplDecl(SharedLocationCall const& Prefix,
    clang::ObjCImplDecl const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{
}

static void GetLocationsObjCImplementationDecl(SharedLocationCall const& Prefix,
    clang::ObjCImplementationDecl const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{

  Locs.insert(LocationAndString(Object.getSuperClassLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getSuperClassLoc")));

  Locs.insert(LocationAndString(Object.getIvarLBraceLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getIvarLBraceLoc")));

  Locs.insert(LocationAndString(Object.getIvarRBraceLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getIvarRBraceLoc")));

}

static void GetLocationsObjCIndirectCopyRestoreExpr(SharedLocationCall const& Prefix,
    clang::ObjCIndirectCopyRestoreExpr const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{
}

static void GetLocationsObjCInterfaceDecl(SharedLocationCall const& Prefix,
    clang::ObjCInterfaceDecl const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{

  Locs.insert(LocationAndString(Object.getEndOfDefinitionLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getEndOfDefinitionLoc")));

  Locs.insert(LocationAndString(Object.getSuperClassLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getSuperClassLoc")));

std::vector<clang::TypeLoc> TypeLocRecursionGuard;



              if (Object.getSuperClassTInfo()) {
                GetLocationsImpl(llvm::makeIntrusiveRefCnt<LocationCall>(
                    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getSuperClassTInfo",
                        LocationCall::ReturnsPointer), "getTypeLoc"),
                    Object.getSuperClassTInfo()->getTypeLoc(), Locs, Rngs, TypeLocRecursionGuard);
                    }
              
}

static void GetLocationsObjCInterfaceTypeLoc(SharedLocationCall const& Prefix,
    clang::ObjCInterfaceTypeLoc const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs , std::vector<clang::TypeLoc>& TypeLocRecursionGuard)
{

  Locs.insert(LocationAndString(Object.getNameLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getNameLoc")));

  Locs.insert(LocationAndString(Object.getNameEndLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getNameEndLoc")));

}

static void GetLocationsObjCIsaExpr(SharedLocationCall const& Prefix,
    clang::ObjCIsaExpr const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{

  Locs.insert(LocationAndString(Object.getIsaMemberLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getIsaMemberLoc")));

  Locs.insert(LocationAndString(Object.getOpLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getOpLoc")));

  Locs.insert(LocationAndString(Object.getBaseLocEnd(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getBaseLocEnd")));

}

static void GetLocationsObjCIvarDecl(SharedLocationCall const& Prefix,
    clang::ObjCIvarDecl const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{
}

static void GetLocationsObjCIvarRefExpr(SharedLocationCall const& Prefix,
    clang::ObjCIvarRefExpr const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{

  Locs.insert(LocationAndString(Object.getLocation(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getLocation")));

  Locs.insert(LocationAndString(Object.getOpLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getOpLoc")));

}

static void GetLocationsObjCMessageExpr(SharedLocationCall const& Prefix,
    clang::ObjCMessageExpr const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{

  Locs.insert(LocationAndString(Object.getSuperLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getSuperLoc")));

  Locs.insert(LocationAndString(Object.getLeftLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getLeftLoc")));

  Locs.insert(LocationAndString(Object.getRightLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getRightLoc")));

  Locs.insert(LocationAndString(Object.getSelectorStartLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getSelectorStartLoc")));


  Rngs.insert(RangeAndString(Object.getReceiverRange(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getReceiverRange")));

std::vector<clang::TypeLoc> TypeLocRecursionGuard;



              if (Object.getClassReceiverTypeInfo()) {
                GetLocationsImpl(llvm::makeIntrusiveRefCnt<LocationCall>(
                    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getClassReceiverTypeInfo",
                        LocationCall::ReturnsPointer), "getTypeLoc"),
                    Object.getClassReceiverTypeInfo()->getTypeLoc(), Locs, Rngs, TypeLocRecursionGuard);
                    }
              
}

static void GetLocationsObjCMethodDecl(SharedLocationCall const& Prefix,
    clang::ObjCMethodDecl const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{

  Locs.insert(LocationAndString(Object.getDeclaratorEndLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getDeclaratorEndLoc")));

  Locs.insert(LocationAndString(Object.getSelectorStartLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getSelectorStartLoc")));


  Rngs.insert(RangeAndString(Object.getReturnTypeSourceRange(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getReturnTypeSourceRange")));

std::vector<clang::TypeLoc> TypeLocRecursionGuard;



              if (Object.getReturnTypeSourceInfo()) {
                GetLocationsImpl(llvm::makeIntrusiveRefCnt<LocationCall>(
                    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getReturnTypeSourceInfo",
                        LocationCall::ReturnsPointer), "getTypeLoc"),
                    Object.getReturnTypeSourceInfo()->getTypeLoc(), Locs, Rngs, TypeLocRecursionGuard);
                    }
              
}

static void GetLocationsObjCObjectPointerTypeLoc(SharedLocationCall const& Prefix,
    clang::ObjCObjectPointerTypeLoc const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs , std::vector<clang::TypeLoc>& TypeLocRecursionGuard)
{

  Locs.insert(LocationAndString(Object.getStarLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getStarLoc")));

}

static void GetLocationsObjCObjectTypeLoc(SharedLocationCall const& Prefix,
    clang::ObjCObjectTypeLoc const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs , std::vector<clang::TypeLoc>& TypeLocRecursionGuard)
{

  Locs.insert(LocationAndString(Object.getTypeArgsLAngleLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getTypeArgsLAngleLoc")));

  Locs.insert(LocationAndString(Object.getTypeArgsRAngleLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getTypeArgsRAngleLoc")));

  Locs.insert(LocationAndString(Object.getProtocolLAngleLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getProtocolLAngleLoc")));

  Locs.insert(LocationAndString(Object.getProtocolRAngleLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getProtocolRAngleLoc")));



              if (Object.getBaseLoc()) {
                GetLocationsImpl(
                    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getBaseLoc"),
                    Object.getBaseLoc(), Locs, Rngs, TypeLocRecursionGuard);
                }
              
}

static void GetLocationsObjCPropertyDecl(SharedLocationCall const& Prefix,
    clang::ObjCPropertyDecl const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{

  Locs.insert(LocationAndString(Object.getAtLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getAtLoc")));

  Locs.insert(LocationAndString(Object.getLParenLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getLParenLoc")));

  Locs.insert(LocationAndString(Object.getGetterNameLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getGetterNameLoc")));

  Locs.insert(LocationAndString(Object.getSetterNameLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getSetterNameLoc")));

std::vector<clang::TypeLoc> TypeLocRecursionGuard;



              if (Object.getTypeSourceInfo()) {
                GetLocationsImpl(llvm::makeIntrusiveRefCnt<LocationCall>(
                    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getTypeSourceInfo",
                        LocationCall::ReturnsPointer), "getTypeLoc"),
                    Object.getTypeSourceInfo()->getTypeLoc(), Locs, Rngs, TypeLocRecursionGuard);
                    }
              
}

static void GetLocationsObjCPropertyImplDecl(SharedLocationCall const& Prefix,
    clang::ObjCPropertyImplDecl const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{

  Locs.insert(LocationAndString(Object.getPropertyIvarDeclLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getPropertyIvarDeclLoc")));

}

static void GetLocationsObjCPropertyRefExpr(SharedLocationCall const& Prefix,
    clang::ObjCPropertyRefExpr const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{

  Locs.insert(LocationAndString(Object.getLocation(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getLocation")));

  Locs.insert(LocationAndString(Object.getReceiverLocation(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getReceiverLocation")));

}

static void GetLocationsObjCProtocolDecl(SharedLocationCall const& Prefix,
    clang::ObjCProtocolDecl const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{
}

static void GetLocationsObjCProtocolExpr(SharedLocationCall const& Prefix,
    clang::ObjCProtocolExpr const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{

  Locs.insert(LocationAndString(Object.getProtocolIdLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getProtocolIdLoc")));

  Locs.insert(LocationAndString(Object.getAtLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getAtLoc")));

  Locs.insert(LocationAndString(Object.getRParenLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getRParenLoc")));

}

static void GetLocationsObjCSelectorExpr(SharedLocationCall const& Prefix,
    clang::ObjCSelectorExpr const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{

  Locs.insert(LocationAndString(Object.getAtLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getAtLoc")));

  Locs.insert(LocationAndString(Object.getRParenLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getRParenLoc")));

}

static void GetLocationsObjCStringLiteral(SharedLocationCall const& Prefix,
    clang::ObjCStringLiteral const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{

  Locs.insert(LocationAndString(Object.getAtLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getAtLoc")));

}

static void GetLocationsObjCSubscriptRefExpr(SharedLocationCall const& Prefix,
    clang::ObjCSubscriptRefExpr const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{

  Locs.insert(LocationAndString(Object.getRBracket(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getRBracket")));

}

static void GetLocationsObjCTypeParamDecl(SharedLocationCall const& Prefix,
    clang::ObjCTypeParamDecl const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{

  Locs.insert(LocationAndString(Object.getVarianceLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getVarianceLoc")));

  Locs.insert(LocationAndString(Object.getColonLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getColonLoc")));

}

static void GetLocationsObjCTypeParamTypeLoc(SharedLocationCall const& Prefix,
    clang::ObjCTypeParamTypeLoc const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs , std::vector<clang::TypeLoc>& TypeLocRecursionGuard)
{

  Locs.insert(LocationAndString(Object.getNameLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getNameLoc")));

  Locs.insert(LocationAndString(Object.getProtocolLAngleLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getProtocolLAngleLoc")));

  Locs.insert(LocationAndString(Object.getProtocolRAngleLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getProtocolRAngleLoc")));

}

static void GetLocationsOffsetOfExpr(SharedLocationCall const& Prefix,
    clang::OffsetOfExpr const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{

  Locs.insert(LocationAndString(Object.getOperatorLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getOperatorLoc")));

  Locs.insert(LocationAndString(Object.getRParenLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getRParenLoc")));

std::vector<clang::TypeLoc> TypeLocRecursionGuard;



              if (Object.getTypeSourceInfo()) {
                GetLocationsImpl(llvm::makeIntrusiveRefCnt<LocationCall>(
                    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getTypeSourceInfo",
                        LocationCall::ReturnsPointer), "getTypeLoc"),
                    Object.getTypeSourceInfo()->getTypeLoc(), Locs, Rngs, TypeLocRecursionGuard);
                    }
              
}

static void GetLocationsOpaqueValueExpr(SharedLocationCall const& Prefix,
    clang::OpaqueValueExpr const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{

  Locs.insert(LocationAndString(Object.getLocation(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getLocation")));

}

static void GetLocationsOverloadExpr(SharedLocationCall const& Prefix,
    clang::OverloadExpr const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{

  Locs.insert(LocationAndString(Object.getNameLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getNameLoc")));

  Locs.insert(LocationAndString(Object.getTemplateKeywordLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getTemplateKeywordLoc")));

  Locs.insert(LocationAndString(Object.getLAngleLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getLAngleLoc")));

  Locs.insert(LocationAndString(Object.getRAngleLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getRAngleLoc")));

std::vector<clang::TypeLoc> TypeLocRecursionGuard;



              if (Object.getQualifierLoc())
                GetLocationsImpl(
                    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getQualifierLoc"),
                    Object.getQualifierLoc(), Locs, Rngs, TypeLocRecursionGuard);
              
                      GetLocationsImpl(
                          llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getNameInfo"),
                          Object.getNameInfo(), Locs, Rngs, TypeLocRecursionGuard);
                      }

static void GetLocationsPackExpansionExpr(SharedLocationCall const& Prefix,
    clang::PackExpansionExpr const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{

  Locs.insert(LocationAndString(Object.getEllipsisLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getEllipsisLoc")));

}

static void GetLocationsPackExpansionTypeLoc(SharedLocationCall const& Prefix,
    clang::PackExpansionTypeLoc const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs , std::vector<clang::TypeLoc>& TypeLocRecursionGuard)
{

  Locs.insert(LocationAndString(Object.getEllipsisLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getEllipsisLoc")));



              if (Object.getPatternLoc()) {
                GetLocationsImpl(
                    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getPatternLoc"),
                    Object.getPatternLoc(), Locs, Rngs, TypeLocRecursionGuard);
                }
              
}

static void GetLocationsParenExpr(SharedLocationCall const& Prefix,
    clang::ParenExpr const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{

  Locs.insert(LocationAndString(Object.getLParen(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getLParen")));

  Locs.insert(LocationAndString(Object.getRParen(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getRParen")));

}

static void GetLocationsParenListExpr(SharedLocationCall const& Prefix,
    clang::ParenListExpr const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{

  Locs.insert(LocationAndString(Object.getLParenLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getLParenLoc")));

  Locs.insert(LocationAndString(Object.getRParenLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getRParenLoc")));

}

static void GetLocationsParenTypeLoc(SharedLocationCall const& Prefix,
    clang::ParenTypeLoc const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs , std::vector<clang::TypeLoc>& TypeLocRecursionGuard)
{

  Locs.insert(LocationAndString(Object.getLParenLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getLParenLoc")));

  Locs.insert(LocationAndString(Object.getRParenLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getRParenLoc")));



              if (Object.getInnerLoc()) {
                GetLocationsImpl(
                    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getInnerLoc"),
                    Object.getInnerLoc(), Locs, Rngs, TypeLocRecursionGuard);
                }
              
}

static void GetLocationsParmVarDecl(SharedLocationCall const& Prefix,
    clang::ParmVarDecl const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{

  Rngs.insert(RangeAndString(Object.getDefaultArgRange(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getDefaultArgRange")));

}

static void GetLocationsPipeTypeLoc(SharedLocationCall const& Prefix,
    clang::PipeTypeLoc const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs , std::vector<clang::TypeLoc>& TypeLocRecursionGuard)
{

  Locs.insert(LocationAndString(Object.getKWLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getKWLoc")));



              if (Object.getValueLoc()) {
                GetLocationsImpl(
                    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getValueLoc"),
                    Object.getValueLoc(), Locs, Rngs, TypeLocRecursionGuard);
                }
              
}
template <typename Derived, typename TypeClass, typename LocalData>

static void GetLocationsPointerLikeTypeLoc(SharedLocationCall const& Prefix,
    clang::PointerLikeTypeLoc<Derived, TypeClass, LocalData> const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs , std::vector<clang::TypeLoc>& TypeLocRecursionGuard)
{

  Locs.insert(LocationAndString(Object.getSigilLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getSigilLoc")));



              if (Object.getPointeeLoc()) {
                GetLocationsImpl(
                    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getPointeeLoc"),
                    Object.getPointeeLoc(), Locs, Rngs, TypeLocRecursionGuard);
                }
              
}

static void GetLocationsPointerTypeLoc(SharedLocationCall const& Prefix,
    clang::PointerTypeLoc const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs , std::vector<clang::TypeLoc>& TypeLocRecursionGuard)
{

  Locs.insert(LocationAndString(Object.getStarLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getStarLoc")));

}

static void GetLocationsPragmaCommentDecl(SharedLocationCall const& Prefix,
    clang::PragmaCommentDecl const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{
}

static void GetLocationsPragmaDetectMismatchDecl(SharedLocationCall const& Prefix,
    clang::PragmaDetectMismatchDecl const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{
}

static void GetLocationsPredefinedExpr(SharedLocationCall const& Prefix,
    clang::PredefinedExpr const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{

  Locs.insert(LocationAndString(Object.getLocation(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getLocation")));

}

static void GetLocationsPseudoObjectExpr(SharedLocationCall const& Prefix,
    clang::PseudoObjectExpr const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{
}

static void GetLocationsQualifiedTypeLoc(SharedLocationCall const& Prefix,
    clang::QualifiedTypeLoc const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs , std::vector<clang::TypeLoc>& TypeLocRecursionGuard)
{


              if (Object.getNextTypeLoc()) {
                GetLocationsImpl(
                    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getNextTypeLoc"),
                    Object.getNextTypeLoc(), Locs, Rngs, TypeLocRecursionGuard);
                }
              
}

static void GetLocationsRValueReferenceTypeLoc(SharedLocationCall const& Prefix,
    clang::RValueReferenceTypeLoc const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs , std::vector<clang::TypeLoc>& TypeLocRecursionGuard)
{

  Locs.insert(LocationAndString(Object.getAmpAmpLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getAmpAmpLoc")));

}

static void GetLocationsRecordDecl(SharedLocationCall const& Prefix,
    clang::RecordDecl const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{
}

static void GetLocationsRecordTypeLoc(SharedLocationCall const& Prefix,
    clang::RecordTypeLoc const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs , std::vector<clang::TypeLoc>& TypeLocRecursionGuard)
{
}

static void GetLocationsRecoveryExpr(SharedLocationCall const& Prefix,
    clang::RecoveryExpr const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{
}

static void GetLocationsRedeclarableTemplateDecl(SharedLocationCall const& Prefix,
    clang::RedeclarableTemplateDecl const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{
}

static void GetLocationsReferenceTypeLoc(SharedLocationCall const& Prefix,
    clang::ReferenceTypeLoc const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs , std::vector<clang::TypeLoc>& TypeLocRecursionGuard)
{
}

static void GetLocationsRequiresExpr(SharedLocationCall const& Prefix,
    clang::RequiresExpr const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{

  Locs.insert(LocationAndString(Object.getRequiresKWLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getRequiresKWLoc")));

  Locs.insert(LocationAndString(Object.getRBraceLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getRBraceLoc")));

}

static void GetLocationsRequiresExprBodyDecl(SharedLocationCall const& Prefix,
    clang::RequiresExprBodyDecl const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{
}

static void GetLocationsReturnStmt(SharedLocationCall const& Prefix,
    clang::ReturnStmt const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{

  Locs.insert(LocationAndString(Object.getReturnLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getReturnLoc")));

}

static void GetLocationsSEHExceptStmt(SharedLocationCall const& Prefix,
    clang::SEHExceptStmt const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{

  Locs.insert(LocationAndString(Object.getExceptLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getExceptLoc")));

}

static void GetLocationsSEHFinallyStmt(SharedLocationCall const& Prefix,
    clang::SEHFinallyStmt const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{

  Locs.insert(LocationAndString(Object.getFinallyLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getFinallyLoc")));

}

static void GetLocationsSEHLeaveStmt(SharedLocationCall const& Prefix,
    clang::SEHLeaveStmt const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{

  Locs.insert(LocationAndString(Object.getLeaveLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getLeaveLoc")));

}

static void GetLocationsSEHTryStmt(SharedLocationCall const& Prefix,
    clang::SEHTryStmt const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{

  Locs.insert(LocationAndString(Object.getTryLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getTryLoc")));

}

static void GetLocationsSYCLUniqueStableNameExpr(SharedLocationCall const& Prefix,
    clang::SYCLUniqueStableNameExpr const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{

  Locs.insert(LocationAndString(Object.getLocation(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getLocation")));

  Locs.insert(LocationAndString(Object.getLParenLocation(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getLParenLocation")));

  Locs.insert(LocationAndString(Object.getRParenLocation(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getRParenLocation")));

}

static void GetLocationsShuffleVectorExpr(SharedLocationCall const& Prefix,
    clang::ShuffleVectorExpr const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{

  Locs.insert(LocationAndString(Object.getBuiltinLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getBuiltinLoc")));

  Locs.insert(LocationAndString(Object.getRParenLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getRParenLoc")));

}

static void GetLocationsSizeOfPackExpr(SharedLocationCall const& Prefix,
    clang::SizeOfPackExpr const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{

  Locs.insert(LocationAndString(Object.getOperatorLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getOperatorLoc")));

  Locs.insert(LocationAndString(Object.getPackLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getPackLoc")));

  Locs.insert(LocationAndString(Object.getRParenLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getRParenLoc")));

}

static void GetLocationsSourceLocExpr(SharedLocationCall const& Prefix,
    clang::SourceLocExpr const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{

  Locs.insert(LocationAndString(Object.getLocation(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getLocation")));

}

static void GetLocationsStaticAssertDecl(SharedLocationCall const& Prefix,
    clang::StaticAssertDecl const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{

  Locs.insert(LocationAndString(Object.getRParenLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getRParenLoc")));

}

static void GetLocationsStmt(SharedLocationCall const& Prefix,
    clang::Stmt const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{

  Locs.insert(LocationAndString(Object.getBeginLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getBeginLoc")));

  Locs.insert(LocationAndString(Object.getEndLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getEndLoc")));


  Rngs.insert(RangeAndString(Object.getSourceRange(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getSourceRange")));

}

static void GetLocationsStmtExpr(SharedLocationCall const& Prefix,
    clang::StmtExpr const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{

  Locs.insert(LocationAndString(Object.getLParenLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getLParenLoc")));

  Locs.insert(LocationAndString(Object.getRParenLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getRParenLoc")));

}

static void GetLocationsStringLiteral(SharedLocationCall const& Prefix,
    clang::StringLiteral const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{
}

static void GetLocationsSubstNonTypeTemplateParmExpr(SharedLocationCall const& Prefix,
    clang::SubstNonTypeTemplateParmExpr const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{

  Locs.insert(LocationAndString(Object.getNameLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getNameLoc")));

}

static void GetLocationsSubstNonTypeTemplateParmPackExpr(SharedLocationCall const& Prefix,
    clang::SubstNonTypeTemplateParmPackExpr const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{

  Locs.insert(LocationAndString(Object.getParameterPackLocation(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getParameterPackLocation")));

}

static void GetLocationsSubstTemplateTypeParmPackTypeLoc(SharedLocationCall const& Prefix,
    clang::SubstTemplateTypeParmPackTypeLoc const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs , std::vector<clang::TypeLoc>& TypeLocRecursionGuard)
{
}

static void GetLocationsSubstTemplateTypeParmTypeLoc(SharedLocationCall const& Prefix,
    clang::SubstTemplateTypeParmTypeLoc const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs , std::vector<clang::TypeLoc>& TypeLocRecursionGuard)
{
}

static void GetLocationsSwitchCase(SharedLocationCall const& Prefix,
    clang::SwitchCase const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{

  Locs.insert(LocationAndString(Object.getKeywordLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getKeywordLoc")));

  Locs.insert(LocationAndString(Object.getColonLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getColonLoc")));

}

static void GetLocationsSwitchStmt(SharedLocationCall const& Prefix,
    clang::SwitchStmt const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{

  Locs.insert(LocationAndString(Object.getSwitchLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getSwitchLoc")));

  Locs.insert(LocationAndString(Object.getLParenLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getLParenLoc")));

  Locs.insert(LocationAndString(Object.getRParenLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getRParenLoc")));

}

static void GetLocationsTagDecl(SharedLocationCall const& Prefix,
    clang::TagDecl const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{

  Locs.insert(LocationAndString(Object.getInnerLocStart(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getInnerLocStart")));

  Locs.insert(LocationAndString(Object.getOuterLocStart(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getOuterLocStart")));


  Rngs.insert(RangeAndString(Object.getBraceRange(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getBraceRange")));

std::vector<clang::TypeLoc> TypeLocRecursionGuard;



              if (Object.getQualifierLoc())
                GetLocationsImpl(
                    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getQualifierLoc"),
                    Object.getQualifierLoc(), Locs, Rngs, TypeLocRecursionGuard);
              }

static void GetLocationsTagTypeLoc(SharedLocationCall const& Prefix,
    clang::TagTypeLoc const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs , std::vector<clang::TypeLoc>& TypeLocRecursionGuard)
{
}

static void GetLocationsTemplateArgumentLoc(SharedLocationCall const& Prefix,
    clang::TemplateArgumentLoc const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs , std::vector<clang::TypeLoc>& TypeLocRecursionGuard)
{

  Locs.insert(LocationAndString(Object.getLocation(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getLocation")));

  Locs.insert(LocationAndString(Object.getTemplateNameLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getTemplateNameLoc")));

  Locs.insert(LocationAndString(Object.getTemplateEllipsisLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getTemplateEllipsisLoc")));


  Rngs.insert(RangeAndString(Object.getSourceRange(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getSourceRange")));




              if (Object.getTypeSourceInfo()) {
                GetLocationsImpl(llvm::makeIntrusiveRefCnt<LocationCall>(
                    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getTypeSourceInfo",
                        LocationCall::ReturnsPointer), "getTypeLoc"),
                    Object.getTypeSourceInfo()->getTypeLoc(), Locs, Rngs, TypeLocRecursionGuard);
                    }
              

              if (Object.getTemplateQualifierLoc())
                GetLocationsImpl(
                    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getTemplateQualifierLoc"),
                    Object.getTemplateQualifierLoc(), Locs, Rngs, TypeLocRecursionGuard);
              }

static void GetLocationsTemplateDecl(SharedLocationCall const& Prefix,
    clang::TemplateDecl const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{
}

static void GetLocationsTemplateParamObjectDecl(SharedLocationCall const& Prefix,
    clang::TemplateParamObjectDecl const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{
}

static void GetLocationsTemplateSpecializationTypeLoc(SharedLocationCall const& Prefix,
    clang::TemplateSpecializationTypeLoc const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs , std::vector<clang::TypeLoc>& TypeLocRecursionGuard)
{

  Locs.insert(LocationAndString(Object.getTemplateKeywordLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getTemplateKeywordLoc")));

  Locs.insert(LocationAndString(Object.getLAngleLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getLAngleLoc")));

  Locs.insert(LocationAndString(Object.getRAngleLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getRAngleLoc")));

  Locs.insert(LocationAndString(Object.getTemplateNameLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getTemplateNameLoc")));

}

static void GetLocationsTemplateTemplateParmDecl(SharedLocationCall const& Prefix,
    clang::TemplateTemplateParmDecl const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{

  Locs.insert(LocationAndString(Object.getDefaultArgumentLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getDefaultArgumentLoc")));

}

static void GetLocationsTemplateTypeParmDecl(SharedLocationCall const& Prefix,
    clang::TemplateTypeParmDecl const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{

  Locs.insert(LocationAndString(Object.getDefaultArgumentLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getDefaultArgumentLoc")));

std::vector<clang::TypeLoc> TypeLocRecursionGuard;



              if (Object.getDefaultArgumentInfo()) {
                GetLocationsImpl(llvm::makeIntrusiveRefCnt<LocationCall>(
                    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getDefaultArgumentInfo",
                        LocationCall::ReturnsPointer), "getTypeLoc"),
                    Object.getDefaultArgumentInfo()->getTypeLoc(), Locs, Rngs, TypeLocRecursionGuard);
                    }
              
}

static void GetLocationsTemplateTypeParmTypeLoc(SharedLocationCall const& Prefix,
    clang::TemplateTypeParmTypeLoc const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs , std::vector<clang::TypeLoc>& TypeLocRecursionGuard)
{
}

static void GetLocationsTranslationUnitDecl(SharedLocationCall const& Prefix,
    clang::TranslationUnitDecl const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{
}

static void GetLocationsTypeAliasDecl(SharedLocationCall const& Prefix,
    clang::TypeAliasDecl const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{
}

static void GetLocationsTypeAliasTemplateDecl(SharedLocationCall const& Prefix,
    clang::TypeAliasTemplateDecl const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{
}

static void GetLocationsTypeDecl(SharedLocationCall const& Prefix,
    clang::TypeDecl const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{
}

static void GetLocationsTypeLoc(SharedLocationCall const& Prefix,
    clang::TypeLoc const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs , std::vector<clang::TypeLoc>& TypeLocRecursionGuard)
{

  Locs.insert(LocationAndString(Object.getBeginLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getBeginLoc")));

  Locs.insert(LocationAndString(Object.getEndLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getEndLoc")));

  Locs.insert(LocationAndString(Object.findNullabilityLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "findNullabilityLoc")));


  Rngs.insert(RangeAndString(Object.getSourceRange(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getSourceRange")));

  Rngs.insert(RangeAndString(Object.getLocalSourceRange(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getLocalSourceRange")));



              if (Object.getNextTypeLoc()) {
                GetLocationsImpl(
                    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getNextTypeLoc"),
                    Object.getNextTypeLoc(), Locs, Rngs, TypeLocRecursionGuard);
                }
              
              if (Object.IgnoreParens()) {
                GetLocationsImpl(
                    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "IgnoreParens"),
                    Object.IgnoreParens(), Locs, Rngs, TypeLocRecursionGuard);
                }
              
              if (Object.findExplicitQualifierLoc()) {
                GetLocationsImpl(
                    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "findExplicitQualifierLoc"),
                    Object.findExplicitQualifierLoc(), Locs, Rngs, TypeLocRecursionGuard);
                }
              
}

static void GetLocationsTypeOfExprTypeLoc(SharedLocationCall const& Prefix,
    clang::TypeOfExprTypeLoc const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs , std::vector<clang::TypeLoc>& TypeLocRecursionGuard)
{
}

static void GetLocationsTypeOfTypeLoc(SharedLocationCall const& Prefix,
    clang::TypeOfTypeLoc const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs , std::vector<clang::TypeLoc>& TypeLocRecursionGuard)
{



              if (Object.getUnderlyingTInfo()) {
                GetLocationsImpl(llvm::makeIntrusiveRefCnt<LocationCall>(
                    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getUnderlyingTInfo",
                        LocationCall::ReturnsPointer), "getTypeLoc"),
                    Object.getUnderlyingTInfo()->getTypeLoc(), Locs, Rngs, TypeLocRecursionGuard);
                    }
              
}

static void GetLocationsTypeSpecTypeLoc(SharedLocationCall const& Prefix,
    clang::TypeSpecTypeLoc const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs , std::vector<clang::TypeLoc>& TypeLocRecursionGuard)
{

  Locs.insert(LocationAndString(Object.getNameLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getNameLoc")));

}

static void GetLocationsTypeTraitExpr(SharedLocationCall const& Prefix,
    clang::TypeTraitExpr const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{
}

static void GetLocationsTypedefDecl(SharedLocationCall const& Prefix,
    clang::TypedefDecl const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{
}

static void GetLocationsTypedefNameDecl(SharedLocationCall const& Prefix,
    clang::TypedefNameDecl const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{
std::vector<clang::TypeLoc> TypeLocRecursionGuard;



              if (Object.getTypeSourceInfo()) {
                GetLocationsImpl(llvm::makeIntrusiveRefCnt<LocationCall>(
                    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getTypeSourceInfo",
                        LocationCall::ReturnsPointer), "getTypeLoc"),
                    Object.getTypeSourceInfo()->getTypeLoc(), Locs, Rngs, TypeLocRecursionGuard);
                    }
              
}

static void GetLocationsTypedefTypeLoc(SharedLocationCall const& Prefix,
    clang::TypedefTypeLoc const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs , std::vector<clang::TypeLoc>& TypeLocRecursionGuard)
{
}
template <typename Derived, typename TypeClass, typename LocalData>

static void GetLocationsTypeofLikeTypeLoc(SharedLocationCall const& Prefix,
    clang::TypeofLikeTypeLoc<Derived, TypeClass, LocalData> const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs , std::vector<clang::TypeLoc>& TypeLocRecursionGuard)
{

  Locs.insert(LocationAndString(Object.getTypeofLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getTypeofLoc")));

  Locs.insert(LocationAndString(Object.getLParenLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getLParenLoc")));

  Locs.insert(LocationAndString(Object.getRParenLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getRParenLoc")));


  Rngs.insert(RangeAndString(Object.getParensRange(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getParensRange")));

}

static void GetLocationsTypoExpr(SharedLocationCall const& Prefix,
    clang::TypoExpr const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{
}

static void GetLocationsUnaryExprOrTypeTraitExpr(SharedLocationCall const& Prefix,
    clang::UnaryExprOrTypeTraitExpr const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{

  Locs.insert(LocationAndString(Object.getOperatorLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getOperatorLoc")));

  Locs.insert(LocationAndString(Object.getRParenLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getRParenLoc")));

std::vector<clang::TypeLoc> TypeLocRecursionGuard;



              if (Object.getArgumentTypeInfo()) {
                GetLocationsImpl(llvm::makeIntrusiveRefCnt<LocationCall>(
                    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getArgumentTypeInfo",
                        LocationCall::ReturnsPointer), "getTypeLoc"),
                    Object.getArgumentTypeInfo()->getTypeLoc(), Locs, Rngs, TypeLocRecursionGuard);
                    }
              
}

static void GetLocationsUnaryOperator(SharedLocationCall const& Prefix,
    clang::UnaryOperator const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{

  Locs.insert(LocationAndString(Object.getOperatorLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getOperatorLoc")));

}

static void GetLocationsUnaryTransformTypeLoc(SharedLocationCall const& Prefix,
    clang::UnaryTransformTypeLoc const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs , std::vector<clang::TypeLoc>& TypeLocRecursionGuard)
{

  Locs.insert(LocationAndString(Object.getKWLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getKWLoc")));

  Locs.insert(LocationAndString(Object.getLParenLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getLParenLoc")));

  Locs.insert(LocationAndString(Object.getRParenLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getRParenLoc")));


  Rngs.insert(RangeAndString(Object.getParensRange(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getParensRange")));




              if (Object.getUnderlyingTInfo()) {
                GetLocationsImpl(llvm::makeIntrusiveRefCnt<LocationCall>(
                    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getUnderlyingTInfo",
                        LocationCall::ReturnsPointer), "getTypeLoc"),
                    Object.getUnderlyingTInfo()->getTypeLoc(), Locs, Rngs, TypeLocRecursionGuard);
                    }
              
}

static void GetLocationsUnqualTypeLoc(SharedLocationCall const& Prefix,
    clang::UnqualTypeLoc const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs , std::vector<clang::TypeLoc>& TypeLocRecursionGuard)
{
}

static void GetLocationsUnresolvedLookupExpr(SharedLocationCall const& Prefix,
    clang::UnresolvedLookupExpr const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{
}

static void GetLocationsUnresolvedMemberExpr(SharedLocationCall const& Prefix,
    clang::UnresolvedMemberExpr const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{

  Locs.insert(LocationAndString(Object.getOperatorLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getOperatorLoc")));

  Locs.insert(LocationAndString(Object.getMemberLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getMemberLoc")));

std::vector<clang::TypeLoc> TypeLocRecursionGuard;



                      GetLocationsImpl(
                          llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getMemberNameInfo"),
                          Object.getMemberNameInfo(), Locs, Rngs, TypeLocRecursionGuard);
                      }

static void GetLocationsUnresolvedUsingIfExistsDecl(SharedLocationCall const& Prefix,
    clang::UnresolvedUsingIfExistsDecl const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{
}

static void GetLocationsUnresolvedUsingTypeLoc(SharedLocationCall const& Prefix,
    clang::UnresolvedUsingTypeLoc const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs , std::vector<clang::TypeLoc>& TypeLocRecursionGuard)
{
}

static void GetLocationsUnresolvedUsingTypenameDecl(SharedLocationCall const& Prefix,
    clang::UnresolvedUsingTypenameDecl const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{

  Locs.insert(LocationAndString(Object.getUsingLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getUsingLoc")));

  Locs.insert(LocationAndString(Object.getTypenameLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getTypenameLoc")));

  Locs.insert(LocationAndString(Object.getEllipsisLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getEllipsisLoc")));

std::vector<clang::TypeLoc> TypeLocRecursionGuard;



              if (Object.getQualifierLoc())
                GetLocationsImpl(
                    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getQualifierLoc"),
                    Object.getQualifierLoc(), Locs, Rngs, TypeLocRecursionGuard);
              
                      GetLocationsImpl(
                          llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getNameInfo"),
                          Object.getNameInfo(), Locs, Rngs, TypeLocRecursionGuard);
                      }

static void GetLocationsUnresolvedUsingValueDecl(SharedLocationCall const& Prefix,
    clang::UnresolvedUsingValueDecl const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{

  Locs.insert(LocationAndString(Object.getUsingLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getUsingLoc")));

  Locs.insert(LocationAndString(Object.getEllipsisLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getEllipsisLoc")));

std::vector<clang::TypeLoc> TypeLocRecursionGuard;



              if (Object.getQualifierLoc())
                GetLocationsImpl(
                    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getQualifierLoc"),
                    Object.getQualifierLoc(), Locs, Rngs, TypeLocRecursionGuard);
              
                      GetLocationsImpl(
                          llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getNameInfo"),
                          Object.getNameInfo(), Locs, Rngs, TypeLocRecursionGuard);
                      }

static void GetLocationsUserDefinedLiteral(SharedLocationCall const& Prefix,
    clang::UserDefinedLiteral const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{

  Locs.insert(LocationAndString(Object.getUDSuffixLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getUDSuffixLoc")));

}

static void GetLocationsUsingDecl(SharedLocationCall const& Prefix,
    clang::UsingDecl const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{

  Locs.insert(LocationAndString(Object.getUsingLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getUsingLoc")));

std::vector<clang::TypeLoc> TypeLocRecursionGuard;



              if (Object.getQualifierLoc())
                GetLocationsImpl(
                    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getQualifierLoc"),
                    Object.getQualifierLoc(), Locs, Rngs, TypeLocRecursionGuard);
              
                      GetLocationsImpl(
                          llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getNameInfo"),
                          Object.getNameInfo(), Locs, Rngs, TypeLocRecursionGuard);
                      }

static void GetLocationsUsingDirectiveDecl(SharedLocationCall const& Prefix,
    clang::UsingDirectiveDecl const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{

  Locs.insert(LocationAndString(Object.getUsingLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getUsingLoc")));

  Locs.insert(LocationAndString(Object.getNamespaceKeyLocation(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getNamespaceKeyLocation")));

  Locs.insert(LocationAndString(Object.getIdentLocation(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getIdentLocation")));

std::vector<clang::TypeLoc> TypeLocRecursionGuard;



              if (Object.getQualifierLoc())
                GetLocationsImpl(
                    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getQualifierLoc"),
                    Object.getQualifierLoc(), Locs, Rngs, TypeLocRecursionGuard);
              }

static void GetLocationsUsingEnumDecl(SharedLocationCall const& Prefix,
    clang::UsingEnumDecl const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{

  Locs.insert(LocationAndString(Object.getUsingLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getUsingLoc")));

  Locs.insert(LocationAndString(Object.getEnumLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getEnumLoc")));

}

static void GetLocationsUsingPackDecl(SharedLocationCall const& Prefix,
    clang::UsingPackDecl const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{
}

static void GetLocationsUsingShadowDecl(SharedLocationCall const& Prefix,
    clang::UsingShadowDecl const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{
}

static void GetLocationsUsingTypeLoc(SharedLocationCall const& Prefix,
    clang::UsingTypeLoc const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs , std::vector<clang::TypeLoc>& TypeLocRecursionGuard)
{
}

static void GetLocationsVAArgExpr(SharedLocationCall const& Prefix,
    clang::VAArgExpr const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{

  Locs.insert(LocationAndString(Object.getBuiltinLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getBuiltinLoc")));

  Locs.insert(LocationAndString(Object.getRParenLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getRParenLoc")));

std::vector<clang::TypeLoc> TypeLocRecursionGuard;



              if (Object.getWrittenTypeInfo()) {
                GetLocationsImpl(llvm::makeIntrusiveRefCnt<LocationCall>(
                    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getWrittenTypeInfo",
                        LocationCall::ReturnsPointer), "getTypeLoc"),
                    Object.getWrittenTypeInfo()->getTypeLoc(), Locs, Rngs, TypeLocRecursionGuard);
                    }
              
}

static void GetLocationsValueDecl(SharedLocationCall const& Prefix,
    clang::ValueDecl const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{
}

static void GetLocationsValueStmt(SharedLocationCall const& Prefix,
    clang::ValueStmt const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{
}

static void GetLocationsVarDecl(SharedLocationCall const& Prefix,
    clang::VarDecl const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{

  Locs.insert(LocationAndString(Object.getPointOfInstantiation(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getPointOfInstantiation")));

}

static void GetLocationsVarTemplateDecl(SharedLocationCall const& Prefix,
    clang::VarTemplateDecl const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{
}

static void GetLocationsVarTemplatePartialSpecializationDecl(SharedLocationCall const& Prefix,
    clang::VarTemplatePartialSpecializationDecl const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{
}

static void GetLocationsVarTemplateSpecializationDecl(SharedLocationCall const& Prefix,
    clang::VarTemplateSpecializationDecl const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{

  Locs.insert(LocationAndString(Object.getPointOfInstantiation(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getPointOfInstantiation")));

  Locs.insert(LocationAndString(Object.getExternLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getExternLoc")));

  Locs.insert(LocationAndString(Object.getTemplateKeywordLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getTemplateKeywordLoc")));

std::vector<clang::TypeLoc> TypeLocRecursionGuard;



              if (Object.getTypeAsWritten()) {
                GetLocationsImpl(llvm::makeIntrusiveRefCnt<LocationCall>(
                    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getTypeAsWritten",
                        LocationCall::ReturnsPointer), "getTypeLoc"),
                    Object.getTypeAsWritten()->getTypeLoc(), Locs, Rngs, TypeLocRecursionGuard);
                    }
              
}

static void GetLocationsVariableArrayTypeLoc(SharedLocationCall const& Prefix,
    clang::VariableArrayTypeLoc const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs , std::vector<clang::TypeLoc>& TypeLocRecursionGuard)
{
}

static void GetLocationsVectorTypeLoc(SharedLocationCall const& Prefix,
    clang::VectorTypeLoc const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs , std::vector<clang::TypeLoc>& TypeLocRecursionGuard)
{

  Locs.insert(LocationAndString(Object.getNameLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getNameLoc")));



              if (Object.getElementLoc()) {
                GetLocationsImpl(
                    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getElementLoc"),
                    Object.getElementLoc(), Locs, Rngs, TypeLocRecursionGuard);
                }
              
}

static void GetLocationsWhileStmt(SharedLocationCall const& Prefix,
    clang::WhileStmt const &Object,
    SourceLocationMap &Locs, SourceRangeMap &Rngs )
{

  Locs.insert(LocationAndString(Object.getWhileLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getWhileLoc")));

  Locs.insert(LocationAndString(Object.getLParenLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getLParenLoc")));

  Locs.insert(LocationAndString(Object.getRParenLoc(),
    llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getRParenLoc")));

}
void 
    GetLocationsImpl(SharedLocationCall const& Prefix,
        clang::CXXBaseSpecifier const *Object, SourceLocationMap &Locs,
        SourceRangeMap &Rngs,
        std::vector<clang::TypeLoc> &TypeLocRecursionGuard)
     { GetLocationsCXXBaseSpecifier(Prefix, *Object, Locs, Rngs );}
NodeLocationAccessors NodeIntrospection::GetLocations(clang::CXXBaseSpecifier const *Object) {
  NodeLocationAccessors Result;
  SharedLocationCall Prefix;
  std::vector<clang::TypeLoc> TypeLocRecursionGuard;

  GetLocationsImpl(Prefix, Object, Result.LocationAccessors,
                   Result.RangeAccessors, TypeLocRecursionGuard);
return Result; }void 
    GetLocationsImpl(SharedLocationCall const& Prefix,
        clang::CXXCtorInitializer const *Object, SourceLocationMap &Locs,
        SourceRangeMap &Rngs,
        std::vector<clang::TypeLoc> &TypeLocRecursionGuard)
     { GetLocationsCXXCtorInitializer(Prefix, *Object, Locs, Rngs );}
NodeLocationAccessors NodeIntrospection::GetLocations(clang::CXXCtorInitializer const *Object) {
  NodeLocationAccessors Result;
  SharedLocationCall Prefix;
  std::vector<clang::TypeLoc> TypeLocRecursionGuard;

  GetLocationsImpl(Prefix, Object, Result.LocationAccessors,
                   Result.RangeAccessors, TypeLocRecursionGuard);
return Result; }void 
    GetLocationsImpl(SharedLocationCall const& Prefix,
        clang::Decl const *Object, SourceLocationMap &Locs,
        SourceRangeMap &Rngs,
        std::vector<clang::TypeLoc> &TypeLocRecursionGuard)
     { GetLocationsDecl(Prefix, *Object, Locs, Rngs );
if (auto Derived = llvm::dyn_cast<clang::TranslationUnitDecl>(Object)) {
  GetLocationsTranslationUnitDecl(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::PragmaCommentDecl>(Object)) {
  GetLocationsPragmaCommentDecl(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::PragmaDetectMismatchDecl>(Object)) {
  GetLocationsPragmaDetectMismatchDecl(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::ExternCContextDecl>(Object)) {
  GetLocationsExternCContextDecl(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::NamedDecl>(Object)) {
  GetLocationsNamedDecl(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::LabelDecl>(Object)) {
  GetLocationsLabelDecl(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::NamespaceDecl>(Object)) {
  GetLocationsNamespaceDecl(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::ValueDecl>(Object)) {
  GetLocationsValueDecl(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::DeclaratorDecl>(Object)) {
  GetLocationsDeclaratorDecl(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::VarDecl>(Object)) {
  GetLocationsVarDecl(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::ImplicitParamDecl>(Object)) {
  GetLocationsImplicitParamDecl(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::ParmVarDecl>(Object)) {
  GetLocationsParmVarDecl(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::FunctionDecl>(Object)) {
  GetLocationsFunctionDecl(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::FieldDecl>(Object)) {
  GetLocationsFieldDecl(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::EnumConstantDecl>(Object)) {
  GetLocationsEnumConstantDecl(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::IndirectFieldDecl>(Object)) {
  GetLocationsIndirectFieldDecl(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::TypeDecl>(Object)) {
  GetLocationsTypeDecl(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::TypedefNameDecl>(Object)) {
  GetLocationsTypedefNameDecl(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::TypedefDecl>(Object)) {
  GetLocationsTypedefDecl(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::TypeAliasDecl>(Object)) {
  GetLocationsTypeAliasDecl(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::TagDecl>(Object)) {
  GetLocationsTagDecl(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::EnumDecl>(Object)) {
  GetLocationsEnumDecl(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::RecordDecl>(Object)) {
  GetLocationsRecordDecl(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::FileScopeAsmDecl>(Object)) {
  GetLocationsFileScopeAsmDecl(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::BlockDecl>(Object)) {
  GetLocationsBlockDecl(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::CapturedDecl>(Object)) {
  GetLocationsCapturedDecl(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::ImportDecl>(Object)) {
  GetLocationsImportDecl(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::ExportDecl>(Object)) {
  GetLocationsExportDecl(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::EmptyDecl>(Object)) {
  GetLocationsEmptyDecl(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::AccessSpecDecl>(Object)) {
  GetLocationsAccessSpecDecl(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::CXXRecordDecl>(Object)) {
  GetLocationsCXXRecordDecl(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::CXXDeductionGuideDecl>(Object)) {
  GetLocationsCXXDeductionGuideDecl(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::RequiresExprBodyDecl>(Object)) {
  GetLocationsRequiresExprBodyDecl(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::CXXMethodDecl>(Object)) {
  GetLocationsCXXMethodDecl(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::CXXConstructorDecl>(Object)) {
  GetLocationsCXXConstructorDecl(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::CXXDestructorDecl>(Object)) {
  GetLocationsCXXDestructorDecl(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::CXXConversionDecl>(Object)) {
  GetLocationsCXXConversionDecl(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::LinkageSpecDecl>(Object)) {
  GetLocationsLinkageSpecDecl(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::UsingDirectiveDecl>(Object)) {
  GetLocationsUsingDirectiveDecl(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::NamespaceAliasDecl>(Object)) {
  GetLocationsNamespaceAliasDecl(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::LifetimeExtendedTemporaryDecl>(Object)) {
  GetLocationsLifetimeExtendedTemporaryDecl(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::UsingShadowDecl>(Object)) {
  GetLocationsUsingShadowDecl(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::BaseUsingDecl>(Object)) {
  GetLocationsBaseUsingDecl(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::UsingDecl>(Object)) {
  GetLocationsUsingDecl(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::ConstructorUsingShadowDecl>(Object)) {
  GetLocationsConstructorUsingShadowDecl(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::UsingEnumDecl>(Object)) {
  GetLocationsUsingEnumDecl(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::UsingPackDecl>(Object)) {
  GetLocationsUsingPackDecl(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::UnresolvedUsingValueDecl>(Object)) {
  GetLocationsUnresolvedUsingValueDecl(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::UnresolvedUsingTypenameDecl>(Object)) {
  GetLocationsUnresolvedUsingTypenameDecl(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::UnresolvedUsingIfExistsDecl>(Object)) {
  GetLocationsUnresolvedUsingIfExistsDecl(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::StaticAssertDecl>(Object)) {
  GetLocationsStaticAssertDecl(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::BindingDecl>(Object)) {
  GetLocationsBindingDecl(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::DecompositionDecl>(Object)) {
  GetLocationsDecompositionDecl(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::MSPropertyDecl>(Object)) {
  GetLocationsMSPropertyDecl(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::MSGuidDecl>(Object)) {
  GetLocationsMSGuidDecl(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::ObjCMethodDecl>(Object)) {
  GetLocationsObjCMethodDecl(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::ObjCTypeParamDecl>(Object)) {
  GetLocationsObjCTypeParamDecl(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::ObjCPropertyDecl>(Object)) {
  GetLocationsObjCPropertyDecl(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::ObjCContainerDecl>(Object)) {
  GetLocationsObjCContainerDecl(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::ObjCInterfaceDecl>(Object)) {
  GetLocationsObjCInterfaceDecl(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::ObjCIvarDecl>(Object)) {
  GetLocationsObjCIvarDecl(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::ObjCAtDefsFieldDecl>(Object)) {
  GetLocationsObjCAtDefsFieldDecl(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::ObjCProtocolDecl>(Object)) {
  GetLocationsObjCProtocolDecl(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::ObjCCategoryDecl>(Object)) {
  GetLocationsObjCCategoryDecl(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::ObjCImplDecl>(Object)) {
  GetLocationsObjCImplDecl(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::ObjCCategoryImplDecl>(Object)) {
  GetLocationsObjCCategoryImplDecl(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::ObjCImplementationDecl>(Object)) {
  GetLocationsObjCImplementationDecl(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::ObjCCompatibleAliasDecl>(Object)) {
  GetLocationsObjCCompatibleAliasDecl(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::ObjCPropertyImplDecl>(Object)) {
  GetLocationsObjCPropertyImplDecl(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::TemplateDecl>(Object)) {
  GetLocationsTemplateDecl(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::RedeclarableTemplateDecl>(Object)) {
  GetLocationsRedeclarableTemplateDecl(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::FunctionTemplateDecl>(Object)) {
  GetLocationsFunctionTemplateDecl(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::TemplateTypeParmDecl>(Object)) {
  GetLocationsTemplateTypeParmDecl(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::NonTypeTemplateParmDecl>(Object)) {
  GetLocationsNonTypeTemplateParmDecl(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::TemplateTemplateParmDecl>(Object)) {
  GetLocationsTemplateTemplateParmDecl(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::BuiltinTemplateDecl>(Object)) {
  GetLocationsBuiltinTemplateDecl(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::ClassTemplateSpecializationDecl>(Object)) {
  GetLocationsClassTemplateSpecializationDecl(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::ClassTemplatePartialSpecializationDecl>(Object)) {
  GetLocationsClassTemplatePartialSpecializationDecl(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::ClassTemplateDecl>(Object)) {
  GetLocationsClassTemplateDecl(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::FriendTemplateDecl>(Object)) {
  GetLocationsFriendTemplateDecl(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::TypeAliasTemplateDecl>(Object)) {
  GetLocationsTypeAliasTemplateDecl(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::ClassScopeFunctionSpecializationDecl>(Object)) {
  GetLocationsClassScopeFunctionSpecializationDecl(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::VarTemplateSpecializationDecl>(Object)) {
  GetLocationsVarTemplateSpecializationDecl(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::VarTemplatePartialSpecializationDecl>(Object)) {
  GetLocationsVarTemplatePartialSpecializationDecl(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::VarTemplateDecl>(Object)) {
  GetLocationsVarTemplateDecl(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::ConceptDecl>(Object)) {
  GetLocationsConceptDecl(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::TemplateParamObjectDecl>(Object)) {
  GetLocationsTemplateParamObjectDecl(Prefix, *Derived, Locs, Rngs );
}
}
NodeLocationAccessors NodeIntrospection::GetLocations(clang::Decl const *Object) {
  NodeLocationAccessors Result;
  SharedLocationCall Prefix;
  std::vector<clang::TypeLoc> TypeLocRecursionGuard;

  GetLocationsImpl(Prefix, Object, Result.LocationAccessors,
                   Result.RangeAccessors, TypeLocRecursionGuard);
return Result; }void 
    GetLocationsImpl(SharedLocationCall const& Prefix,
        clang::DeclarationNameInfo const &Object, SourceLocationMap &Locs,
        SourceRangeMap &Rngs,
        std::vector<clang::TypeLoc> &TypeLocRecursionGuard)
     { GetLocationsDeclarationNameInfo(Prefix, Object, Locs, Rngs , TypeLocRecursionGuard);}
NodeLocationAccessors NodeIntrospection::GetLocations(clang::DeclarationNameInfo const &Object) {
  NodeLocationAccessors Result;
  SharedLocationCall Prefix;
  std::vector<clang::TypeLoc> TypeLocRecursionGuard;

  GetLocationsImpl(Prefix, Object, Result.LocationAccessors,
                   Result.RangeAccessors, TypeLocRecursionGuard);
return Result; }void 
    GetLocationsImpl(SharedLocationCall const& Prefix,
        clang::NestedNameSpecifierLoc const &Object, SourceLocationMap &Locs,
        SourceRangeMap &Rngs,
        std::vector<clang::TypeLoc> &TypeLocRecursionGuard)
     { GetLocationsNestedNameSpecifierLoc(Prefix, Object, Locs, Rngs , TypeLocRecursionGuard);}
NodeLocationAccessors NodeIntrospection::GetLocations(clang::NestedNameSpecifierLoc const &Object) {
  NodeLocationAccessors Result;
  SharedLocationCall Prefix;
  std::vector<clang::TypeLoc> TypeLocRecursionGuard;

  GetLocationsImpl(Prefix, Object, Result.LocationAccessors,
                   Result.RangeAccessors, TypeLocRecursionGuard);
return Result; }void 
    GetLocationsImpl(SharedLocationCall const& Prefix,
        clang::Stmt const *Object, SourceLocationMap &Locs,
        SourceRangeMap &Rngs,
        std::vector<clang::TypeLoc> &TypeLocRecursionGuard)
     { GetLocationsStmt(Prefix, *Object, Locs, Rngs );
if (auto Derived = llvm::dyn_cast<clang::DeclStmt>(Object)) {
  GetLocationsDeclStmt(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::NullStmt>(Object)) {
  GetLocationsNullStmt(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::CompoundStmt>(Object)) {
  GetLocationsCompoundStmt(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::SwitchCase>(Object)) {
  GetLocationsSwitchCase(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::CaseStmt>(Object)) {
  GetLocationsCaseStmt(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::DefaultStmt>(Object)) {
  GetLocationsDefaultStmt(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::ValueStmt>(Object)) {
  GetLocationsValueStmt(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::LabelStmt>(Object)) {
  GetLocationsLabelStmt(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::AttributedStmt>(Object)) {
  GetLocationsAttributedStmt(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::IfStmt>(Object)) {
  GetLocationsIfStmt(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::SwitchStmt>(Object)) {
  GetLocationsSwitchStmt(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::WhileStmt>(Object)) {
  GetLocationsWhileStmt(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::DoStmt>(Object)) {
  GetLocationsDoStmt(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::ForStmt>(Object)) {
  GetLocationsForStmt(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::GotoStmt>(Object)) {
  GetLocationsGotoStmt(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::IndirectGotoStmt>(Object)) {
  GetLocationsIndirectGotoStmt(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::ContinueStmt>(Object)) {
  GetLocationsContinueStmt(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::BreakStmt>(Object)) {
  GetLocationsBreakStmt(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::ReturnStmt>(Object)) {
  GetLocationsReturnStmt(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::AsmStmt>(Object)) {
  GetLocationsAsmStmt(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::GCCAsmStmt>(Object)) {
  GetLocationsGCCAsmStmt(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::MSAsmStmt>(Object)) {
  GetLocationsMSAsmStmt(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::SEHExceptStmt>(Object)) {
  GetLocationsSEHExceptStmt(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::SEHFinallyStmt>(Object)) {
  GetLocationsSEHFinallyStmt(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::SEHTryStmt>(Object)) {
  GetLocationsSEHTryStmt(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::SEHLeaveStmt>(Object)) {
  GetLocationsSEHLeaveStmt(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::CapturedStmt>(Object)) {
  GetLocationsCapturedStmt(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::Expr>(Object)) {
  GetLocationsExpr(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::FullExpr>(Object)) {
  GetLocationsFullExpr(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::ConstantExpr>(Object)) {
  GetLocationsConstantExpr(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::OpaqueValueExpr>(Object)) {
  GetLocationsOpaqueValueExpr(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::DeclRefExpr>(Object)) {
  GetLocationsDeclRefExpr(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::IntegerLiteral>(Object)) {
  GetLocationsIntegerLiteral(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::FixedPointLiteral>(Object)) {
  GetLocationsFixedPointLiteral(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::CharacterLiteral>(Object)) {
  GetLocationsCharacterLiteral(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::FloatingLiteral>(Object)) {
  GetLocationsFloatingLiteral(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::ImaginaryLiteral>(Object)) {
  GetLocationsImaginaryLiteral(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::StringLiteral>(Object)) {
  GetLocationsStringLiteral(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::PredefinedExpr>(Object)) {
  GetLocationsPredefinedExpr(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::SYCLUniqueStableNameExpr>(Object)) {
  GetLocationsSYCLUniqueStableNameExpr(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::ParenExpr>(Object)) {
  GetLocationsParenExpr(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::UnaryOperator>(Object)) {
  GetLocationsUnaryOperator(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::OffsetOfExpr>(Object)) {
  GetLocationsOffsetOfExpr(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::UnaryExprOrTypeTraitExpr>(Object)) {
  GetLocationsUnaryExprOrTypeTraitExpr(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::ArraySubscriptExpr>(Object)) {
  GetLocationsArraySubscriptExpr(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::MatrixSubscriptExpr>(Object)) {
  GetLocationsMatrixSubscriptExpr(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::CallExpr>(Object)) {
  GetLocationsCallExpr(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::MemberExpr>(Object)) {
  GetLocationsMemberExpr(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::CompoundLiteralExpr>(Object)) {
  GetLocationsCompoundLiteralExpr(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::CastExpr>(Object)) {
  GetLocationsCastExpr(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::ImplicitCastExpr>(Object)) {
  GetLocationsImplicitCastExpr(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::ExplicitCastExpr>(Object)) {
  GetLocationsExplicitCastExpr(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::CStyleCastExpr>(Object)) {
  GetLocationsCStyleCastExpr(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::BinaryOperator>(Object)) {
  GetLocationsBinaryOperator(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::CompoundAssignOperator>(Object)) {
  GetLocationsCompoundAssignOperator(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::AbstractConditionalOperator>(Object)) {
  GetLocationsAbstractConditionalOperator(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::ConditionalOperator>(Object)) {
  GetLocationsConditionalOperator(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::BinaryConditionalOperator>(Object)) {
  GetLocationsBinaryConditionalOperator(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::AddrLabelExpr>(Object)) {
  GetLocationsAddrLabelExpr(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::StmtExpr>(Object)) {
  GetLocationsStmtExpr(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::ShuffleVectorExpr>(Object)) {
  GetLocationsShuffleVectorExpr(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::ConvertVectorExpr>(Object)) {
  GetLocationsConvertVectorExpr(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::ChooseExpr>(Object)) {
  GetLocationsChooseExpr(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::GNUNullExpr>(Object)) {
  GetLocationsGNUNullExpr(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::VAArgExpr>(Object)) {
  GetLocationsVAArgExpr(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::SourceLocExpr>(Object)) {
  GetLocationsSourceLocExpr(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::InitListExpr>(Object)) {
  GetLocationsInitListExpr(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::DesignatedInitExpr>(Object)) {
  GetLocationsDesignatedInitExpr(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::NoInitExpr>(Object)) {
  GetLocationsNoInitExpr(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::DesignatedInitUpdateExpr>(Object)) {
  GetLocationsDesignatedInitUpdateExpr(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::ArrayInitLoopExpr>(Object)) {
  GetLocationsArrayInitLoopExpr(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::ArrayInitIndexExpr>(Object)) {
  GetLocationsArrayInitIndexExpr(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::ImplicitValueInitExpr>(Object)) {
  GetLocationsImplicitValueInitExpr(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::ParenListExpr>(Object)) {
  GetLocationsParenListExpr(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::GenericSelectionExpr>(Object)) {
  GetLocationsGenericSelectionExpr(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::ExtVectorElementExpr>(Object)) {
  GetLocationsExtVectorElementExpr(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::BlockExpr>(Object)) {
  GetLocationsBlockExpr(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::AsTypeExpr>(Object)) {
  GetLocationsAsTypeExpr(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::PseudoObjectExpr>(Object)) {
  GetLocationsPseudoObjectExpr(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::AtomicExpr>(Object)) {
  GetLocationsAtomicExpr(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::TypoExpr>(Object)) {
  GetLocationsTypoExpr(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::RecoveryExpr>(Object)) {
  GetLocationsRecoveryExpr(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::ObjCStringLiteral>(Object)) {
  GetLocationsObjCStringLiteral(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::ObjCBoolLiteralExpr>(Object)) {
  GetLocationsObjCBoolLiteralExpr(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::ObjCBoxedExpr>(Object)) {
  GetLocationsObjCBoxedExpr(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::ObjCArrayLiteral>(Object)) {
  GetLocationsObjCArrayLiteral(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::ObjCDictionaryLiteral>(Object)) {
  GetLocationsObjCDictionaryLiteral(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::ObjCEncodeExpr>(Object)) {
  GetLocationsObjCEncodeExpr(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::ObjCSelectorExpr>(Object)) {
  GetLocationsObjCSelectorExpr(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::ObjCProtocolExpr>(Object)) {
  GetLocationsObjCProtocolExpr(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::ObjCIvarRefExpr>(Object)) {
  GetLocationsObjCIvarRefExpr(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::ObjCPropertyRefExpr>(Object)) {
  GetLocationsObjCPropertyRefExpr(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::ObjCSubscriptRefExpr>(Object)) {
  GetLocationsObjCSubscriptRefExpr(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::ObjCMessageExpr>(Object)) {
  GetLocationsObjCMessageExpr(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::ObjCIsaExpr>(Object)) {
  GetLocationsObjCIsaExpr(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::ObjCIndirectCopyRestoreExpr>(Object)) {
  GetLocationsObjCIndirectCopyRestoreExpr(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::ObjCBridgedCastExpr>(Object)) {
  GetLocationsObjCBridgedCastExpr(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::ObjCAvailabilityCheckExpr>(Object)) {
  GetLocationsObjCAvailabilityCheckExpr(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::ConceptSpecializationExpr>(Object)) {
  GetLocationsConceptSpecializationExpr(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::RequiresExpr>(Object)) {
  GetLocationsRequiresExpr(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::CXXCatchStmt>(Object)) {
  GetLocationsCXXCatchStmt(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::CXXTryStmt>(Object)) {
  GetLocationsCXXTryStmt(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::CXXForRangeStmt>(Object)) {
  GetLocationsCXXForRangeStmt(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::MSDependentExistsStmt>(Object)) {
  GetLocationsMSDependentExistsStmt(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::CoroutineBodyStmt>(Object)) {
  GetLocationsCoroutineBodyStmt(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::CoreturnStmt>(Object)) {
  GetLocationsCoreturnStmt(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::CXXOperatorCallExpr>(Object)) {
  GetLocationsCXXOperatorCallExpr(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::CXXMemberCallExpr>(Object)) {
  GetLocationsCXXMemberCallExpr(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::CUDAKernelCallExpr>(Object)) {
  GetLocationsCUDAKernelCallExpr(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::CXXRewrittenBinaryOperator>(Object)) {
  GetLocationsCXXRewrittenBinaryOperator(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::CXXNamedCastExpr>(Object)) {
  GetLocationsCXXNamedCastExpr(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::CXXStaticCastExpr>(Object)) {
  GetLocationsCXXStaticCastExpr(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::CXXDynamicCastExpr>(Object)) {
  GetLocationsCXXDynamicCastExpr(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::CXXReinterpretCastExpr>(Object)) {
  GetLocationsCXXReinterpretCastExpr(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::CXXConstCastExpr>(Object)) {
  GetLocationsCXXConstCastExpr(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::CXXAddrspaceCastExpr>(Object)) {
  GetLocationsCXXAddrspaceCastExpr(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::UserDefinedLiteral>(Object)) {
  GetLocationsUserDefinedLiteral(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::CXXBoolLiteralExpr>(Object)) {
  GetLocationsCXXBoolLiteralExpr(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::CXXNullPtrLiteralExpr>(Object)) {
  GetLocationsCXXNullPtrLiteralExpr(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::CXXStdInitializerListExpr>(Object)) {
  GetLocationsCXXStdInitializerListExpr(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::CXXTypeidExpr>(Object)) {
  GetLocationsCXXTypeidExpr(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::MSPropertyRefExpr>(Object)) {
  GetLocationsMSPropertyRefExpr(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::MSPropertySubscriptExpr>(Object)) {
  GetLocationsMSPropertySubscriptExpr(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::CXXUuidofExpr>(Object)) {
  GetLocationsCXXUuidofExpr(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::CXXThisExpr>(Object)) {
  GetLocationsCXXThisExpr(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::CXXThrowExpr>(Object)) {
  GetLocationsCXXThrowExpr(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::CXXDefaultArgExpr>(Object)) {
  GetLocationsCXXDefaultArgExpr(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::CXXDefaultInitExpr>(Object)) {
  GetLocationsCXXDefaultInitExpr(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::CXXBindTemporaryExpr>(Object)) {
  GetLocationsCXXBindTemporaryExpr(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::CXXConstructExpr>(Object)) {
  GetLocationsCXXConstructExpr(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::CXXInheritedCtorInitExpr>(Object)) {
  GetLocationsCXXInheritedCtorInitExpr(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::CXXFunctionalCastExpr>(Object)) {
  GetLocationsCXXFunctionalCastExpr(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::CXXTemporaryObjectExpr>(Object)) {
  GetLocationsCXXTemporaryObjectExpr(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::LambdaExpr>(Object)) {
  GetLocationsLambdaExpr(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::CXXScalarValueInitExpr>(Object)) {
  GetLocationsCXXScalarValueInitExpr(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::CXXNewExpr>(Object)) {
  GetLocationsCXXNewExpr(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::CXXDeleteExpr>(Object)) {
  GetLocationsCXXDeleteExpr(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::CXXPseudoDestructorExpr>(Object)) {
  GetLocationsCXXPseudoDestructorExpr(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::TypeTraitExpr>(Object)) {
  GetLocationsTypeTraitExpr(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::ArrayTypeTraitExpr>(Object)) {
  GetLocationsArrayTypeTraitExpr(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::ExpressionTraitExpr>(Object)) {
  GetLocationsExpressionTraitExpr(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::OverloadExpr>(Object)) {
  GetLocationsOverloadExpr(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::UnresolvedLookupExpr>(Object)) {
  GetLocationsUnresolvedLookupExpr(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::DependentScopeDeclRefExpr>(Object)) {
  GetLocationsDependentScopeDeclRefExpr(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::ExprWithCleanups>(Object)) {
  GetLocationsExprWithCleanups(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::CXXUnresolvedConstructExpr>(Object)) {
  GetLocationsCXXUnresolvedConstructExpr(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::CXXDependentScopeMemberExpr>(Object)) {
  GetLocationsCXXDependentScopeMemberExpr(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::UnresolvedMemberExpr>(Object)) {
  GetLocationsUnresolvedMemberExpr(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::CXXNoexceptExpr>(Object)) {
  GetLocationsCXXNoexceptExpr(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::PackExpansionExpr>(Object)) {
  GetLocationsPackExpansionExpr(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::SizeOfPackExpr>(Object)) {
  GetLocationsSizeOfPackExpr(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::SubstNonTypeTemplateParmExpr>(Object)) {
  GetLocationsSubstNonTypeTemplateParmExpr(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::SubstNonTypeTemplateParmPackExpr>(Object)) {
  GetLocationsSubstNonTypeTemplateParmPackExpr(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::FunctionParmPackExpr>(Object)) {
  GetLocationsFunctionParmPackExpr(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::MaterializeTemporaryExpr>(Object)) {
  GetLocationsMaterializeTemporaryExpr(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::CXXFoldExpr>(Object)) {
  GetLocationsCXXFoldExpr(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::CoroutineSuspendExpr>(Object)) {
  GetLocationsCoroutineSuspendExpr(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::CoawaitExpr>(Object)) {
  GetLocationsCoawaitExpr(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::DependentCoawaitExpr>(Object)) {
  GetLocationsDependentCoawaitExpr(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::CoyieldExpr>(Object)) {
  GetLocationsCoyieldExpr(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::BuiltinBitCastExpr>(Object)) {
  GetLocationsBuiltinBitCastExpr(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::OMPArraySectionExpr>(Object)) {
  GetLocationsOMPArraySectionExpr(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::OMPArrayShapingExpr>(Object)) {
  GetLocationsOMPArrayShapingExpr(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::OMPIteratorExpr>(Object)) {
  GetLocationsOMPIteratorExpr(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::ObjCForCollectionStmt>(Object)) {
  GetLocationsObjCForCollectionStmt(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::ObjCAtCatchStmt>(Object)) {
  GetLocationsObjCAtCatchStmt(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::ObjCAtFinallyStmt>(Object)) {
  GetLocationsObjCAtFinallyStmt(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::ObjCAtTryStmt>(Object)) {
  GetLocationsObjCAtTryStmt(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::ObjCAtSynchronizedStmt>(Object)) {
  GetLocationsObjCAtSynchronizedStmt(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::ObjCAtThrowStmt>(Object)) {
  GetLocationsObjCAtThrowStmt(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::ObjCAutoreleasePoolStmt>(Object)) {
  GetLocationsObjCAutoreleasePoolStmt(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::OMPCanonicalLoop>(Object)) {
  GetLocationsOMPCanonicalLoop(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::OMPExecutableDirective>(Object)) {
  GetLocationsOMPExecutableDirective(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::OMPParallelDirective>(Object)) {
  GetLocationsOMPParallelDirective(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::OMPLoopBasedDirective>(Object)) {
  GetLocationsOMPLoopBasedDirective(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::OMPLoopTransformationDirective>(Object)) {
  GetLocationsOMPLoopTransformationDirective(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::OMPLoopDirective>(Object)) {
  GetLocationsOMPLoopDirective(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::OMPSimdDirective>(Object)) {
  GetLocationsOMPSimdDirective(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::OMPForDirective>(Object)) {
  GetLocationsOMPForDirective(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::OMPForSimdDirective>(Object)) {
  GetLocationsOMPForSimdDirective(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::OMPSectionsDirective>(Object)) {
  GetLocationsOMPSectionsDirective(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::OMPSectionDirective>(Object)) {
  GetLocationsOMPSectionDirective(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::OMPSingleDirective>(Object)) {
  GetLocationsOMPSingleDirective(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::OMPMasterDirective>(Object)) {
  GetLocationsOMPMasterDirective(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::OMPCriticalDirective>(Object)) {
  GetLocationsOMPCriticalDirective(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::OMPParallelForDirective>(Object)) {
  GetLocationsOMPParallelForDirective(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::OMPParallelForSimdDirective>(Object)) {
  GetLocationsOMPParallelForSimdDirective(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::OMPParallelMasterDirective>(Object)) {
  GetLocationsOMPParallelMasterDirective(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::OMPParallelSectionsDirective>(Object)) {
  GetLocationsOMPParallelSectionsDirective(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::OMPTaskDirective>(Object)) {
  GetLocationsOMPTaskDirective(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::OMPTaskyieldDirective>(Object)) {
  GetLocationsOMPTaskyieldDirective(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::OMPBarrierDirective>(Object)) {
  GetLocationsOMPBarrierDirective(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::OMPTaskwaitDirective>(Object)) {
  GetLocationsOMPTaskwaitDirective(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::OMPTaskgroupDirective>(Object)) {
  GetLocationsOMPTaskgroupDirective(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::OMPFlushDirective>(Object)) {
  GetLocationsOMPFlushDirective(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::OMPDepobjDirective>(Object)) {
  GetLocationsOMPDepobjDirective(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::OMPOrderedDirective>(Object)) {
  GetLocationsOMPOrderedDirective(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::OMPAtomicDirective>(Object)) {
  GetLocationsOMPAtomicDirective(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::OMPTargetDirective>(Object)) {
  GetLocationsOMPTargetDirective(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::OMPTargetDataDirective>(Object)) {
  GetLocationsOMPTargetDataDirective(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::OMPTargetEnterDataDirective>(Object)) {
  GetLocationsOMPTargetEnterDataDirective(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::OMPTargetExitDataDirective>(Object)) {
  GetLocationsOMPTargetExitDataDirective(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::OMPTargetParallelDirective>(Object)) {
  GetLocationsOMPTargetParallelDirective(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::OMPTargetParallelForDirective>(Object)) {
  GetLocationsOMPTargetParallelForDirective(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::OMPTeamsDirective>(Object)) {
  GetLocationsOMPTeamsDirective(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::OMPCancellationPointDirective>(Object)) {
  GetLocationsOMPCancellationPointDirective(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::OMPCancelDirective>(Object)) {
  GetLocationsOMPCancelDirective(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::OMPTaskLoopDirective>(Object)) {
  GetLocationsOMPTaskLoopDirective(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::OMPTaskLoopSimdDirective>(Object)) {
  GetLocationsOMPTaskLoopSimdDirective(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::OMPMasterTaskLoopDirective>(Object)) {
  GetLocationsOMPMasterTaskLoopDirective(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::OMPMasterTaskLoopSimdDirective>(Object)) {
  GetLocationsOMPMasterTaskLoopSimdDirective(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::OMPParallelMasterTaskLoopDirective>(Object)) {
  GetLocationsOMPParallelMasterTaskLoopDirective(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::OMPParallelMasterTaskLoopSimdDirective>(Object)) {
  GetLocationsOMPParallelMasterTaskLoopSimdDirective(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::OMPDistributeDirective>(Object)) {
  GetLocationsOMPDistributeDirective(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::OMPTargetUpdateDirective>(Object)) {
  GetLocationsOMPTargetUpdateDirective(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::OMPDistributeParallelForDirective>(Object)) {
  GetLocationsOMPDistributeParallelForDirective(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::OMPDistributeParallelForSimdDirective>(Object)) {
  GetLocationsOMPDistributeParallelForSimdDirective(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::OMPDistributeSimdDirective>(Object)) {
  GetLocationsOMPDistributeSimdDirective(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::OMPTargetParallelForSimdDirective>(Object)) {
  GetLocationsOMPTargetParallelForSimdDirective(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::OMPTargetSimdDirective>(Object)) {
  GetLocationsOMPTargetSimdDirective(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::OMPTeamsDistributeDirective>(Object)) {
  GetLocationsOMPTeamsDistributeDirective(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::OMPTeamsDistributeSimdDirective>(Object)) {
  GetLocationsOMPTeamsDistributeSimdDirective(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::OMPTeamsDistributeParallelForSimdDirective>(Object)) {
  GetLocationsOMPTeamsDistributeParallelForSimdDirective(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::OMPTeamsDistributeParallelForDirective>(Object)) {
  GetLocationsOMPTeamsDistributeParallelForDirective(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::OMPTargetTeamsDirective>(Object)) {
  GetLocationsOMPTargetTeamsDirective(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::OMPTargetTeamsDistributeDirective>(Object)) {
  GetLocationsOMPTargetTeamsDistributeDirective(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::OMPTargetTeamsDistributeParallelForDirective>(Object)) {
  GetLocationsOMPTargetTeamsDistributeParallelForDirective(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::OMPTargetTeamsDistributeParallelForSimdDirective>(Object)) {
  GetLocationsOMPTargetTeamsDistributeParallelForSimdDirective(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::OMPTargetTeamsDistributeSimdDirective>(Object)) {
  GetLocationsOMPTargetTeamsDistributeSimdDirective(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::OMPTileDirective>(Object)) {
  GetLocationsOMPTileDirective(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::OMPUnrollDirective>(Object)) {
  GetLocationsOMPUnrollDirective(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::OMPScanDirective>(Object)) {
  GetLocationsOMPScanDirective(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::OMPInteropDirective>(Object)) {
  GetLocationsOMPInteropDirective(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::OMPDispatchDirective>(Object)) {
  GetLocationsOMPDispatchDirective(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::OMPMaskedDirective>(Object)) {
  GetLocationsOMPMaskedDirective(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::OMPMetaDirective>(Object)) {
  GetLocationsOMPMetaDirective(Prefix, *Derived, Locs, Rngs );
}

if (auto Derived = llvm::dyn_cast<clang::OMPGenericLoopDirective>(Object)) {
  GetLocationsOMPGenericLoopDirective(Prefix, *Derived, Locs, Rngs );
}
}
NodeLocationAccessors NodeIntrospection::GetLocations(clang::Stmt const *Object) {
  NodeLocationAccessors Result;
  SharedLocationCall Prefix;
  std::vector<clang::TypeLoc> TypeLocRecursionGuard;

  GetLocationsImpl(Prefix, Object, Result.LocationAccessors,
                   Result.RangeAccessors, TypeLocRecursionGuard);
return Result; }void 
    GetLocationsImpl(SharedLocationCall const& Prefix,
        clang::TemplateArgumentLoc const &Object, SourceLocationMap &Locs,
        SourceRangeMap &Rngs,
        std::vector<clang::TypeLoc> &TypeLocRecursionGuard)
     { GetLocationsTemplateArgumentLoc(Prefix, Object, Locs, Rngs , TypeLocRecursionGuard);}
NodeLocationAccessors NodeIntrospection::GetLocations(clang::TemplateArgumentLoc const &Object) {
  NodeLocationAccessors Result;
  SharedLocationCall Prefix;
  std::vector<clang::TypeLoc> TypeLocRecursionGuard;

  GetLocationsImpl(Prefix, Object, Result.LocationAccessors,
                   Result.RangeAccessors, TypeLocRecursionGuard);
return Result; }void 
    GetLocationsImpl(SharedLocationCall const& Prefix,
        clang::TypeLoc const &Object, SourceLocationMap &Locs,
        SourceRangeMap &Rngs,
        std::vector<clang::TypeLoc> &TypeLocRecursionGuard)
     { if (Object.isNull()) return;
            if (llvm::find(TypeLocRecursionGuard, Object) != TypeLocRecursionGuard.end())
              return;
            TypeLocRecursionGuard.push_back(Object);
            RecursionPopper RAII(TypeLocRecursionGuard);
                GetLocationsTypeLoc(Prefix, Object, Locs, Rngs , TypeLocRecursionGuard);
        if (auto QTL = Object.getAs<clang::QualifiedTypeLoc>()) {
            auto Dequalified = QTL.getNextTypeLoc();
            return GetLocationsImpl(llvm::makeIntrusiveRefCnt<LocationCall>(Prefix, "getNextTypeLoc"),
                                Dequalified,
                                Locs,
                                Rngs,
                                TypeLocRecursionGuard);
        }
            if (auto ConcreteTL = Object.getAs<clang::UnqualTypeLoc>())
              GetLocationsUnqualTypeLoc(llvm::makeIntrusiveRefCnt<LocationCall>(Prefix,
                    "getAs<clang::UnqualTypeLoc>", LocationCall::IsCast)
                , ConcreteTL, Locs, Rngs , TypeLocRecursionGuard);
            
            if (auto ConcreteTL = Object.getAs<clang::QualifiedTypeLoc>())
              GetLocationsQualifiedTypeLoc(llvm::makeIntrusiveRefCnt<LocationCall>(Prefix,
                    "getAs<clang::QualifiedTypeLoc>", LocationCall::IsCast)
                , ConcreteTL, Locs, Rngs , TypeLocRecursionGuard);
            
            if (auto ConcreteTL = Object.getAs<clang::TypeSpecTypeLoc>())
              GetLocationsTypeSpecTypeLoc(llvm::makeIntrusiveRefCnt<LocationCall>(Prefix,
                    "getAs<clang::TypeSpecTypeLoc>", LocationCall::IsCast)
                , ConcreteTL, Locs, Rngs , TypeLocRecursionGuard);
            
            if (auto ConcreteTL = Object.getAs<clang::BuiltinTypeLoc>())
              GetLocationsBuiltinTypeLoc(llvm::makeIntrusiveRefCnt<LocationCall>(Prefix,
                    "getAs<clang::BuiltinTypeLoc>", LocationCall::IsCast)
                , ConcreteTL, Locs, Rngs , TypeLocRecursionGuard);
            
            if (auto ConcreteTL = Object.getAs<clang::UsingTypeLoc>())
              GetLocationsUsingTypeLoc(llvm::makeIntrusiveRefCnt<LocationCall>(Prefix,
                    "getAs<clang::UsingTypeLoc>", LocationCall::IsCast)
                , ConcreteTL, Locs, Rngs , TypeLocRecursionGuard);
            
            if (auto ConcreteTL = Object.getAs<clang::TypedefTypeLoc>())
              GetLocationsTypedefTypeLoc(llvm::makeIntrusiveRefCnt<LocationCall>(Prefix,
                    "getAs<clang::TypedefTypeLoc>", LocationCall::IsCast)
                , ConcreteTL, Locs, Rngs , TypeLocRecursionGuard);
            
            if (auto ConcreteTL = Object.getAs<clang::InjectedClassNameTypeLoc>())
              GetLocationsInjectedClassNameTypeLoc(llvm::makeIntrusiveRefCnt<LocationCall>(Prefix,
                    "getAs<clang::InjectedClassNameTypeLoc>", LocationCall::IsCast)
                , ConcreteTL, Locs, Rngs , TypeLocRecursionGuard);
            
            if (auto ConcreteTL = Object.getAs<clang::UnresolvedUsingTypeLoc>())
              GetLocationsUnresolvedUsingTypeLoc(llvm::makeIntrusiveRefCnt<LocationCall>(Prefix,
                    "getAs<clang::UnresolvedUsingTypeLoc>", LocationCall::IsCast)
                , ConcreteTL, Locs, Rngs , TypeLocRecursionGuard);
            
            if (auto ConcreteTL = Object.getAs<clang::TagTypeLoc>())
              GetLocationsTagTypeLoc(llvm::makeIntrusiveRefCnt<LocationCall>(Prefix,
                    "getAs<clang::TagTypeLoc>", LocationCall::IsCast)
                , ConcreteTL, Locs, Rngs , TypeLocRecursionGuard);
            
            if (auto ConcreteTL = Object.getAs<clang::RecordTypeLoc>())
              GetLocationsRecordTypeLoc(llvm::makeIntrusiveRefCnt<LocationCall>(Prefix,
                    "getAs<clang::RecordTypeLoc>", LocationCall::IsCast)
                , ConcreteTL, Locs, Rngs , TypeLocRecursionGuard);
            
            if (auto ConcreteTL = Object.getAs<clang::EnumTypeLoc>())
              GetLocationsEnumTypeLoc(llvm::makeIntrusiveRefCnt<LocationCall>(Prefix,
                    "getAs<clang::EnumTypeLoc>", LocationCall::IsCast)
                , ConcreteTL, Locs, Rngs , TypeLocRecursionGuard);
            
            if (auto ConcreteTL = Object.getAs<clang::TemplateTypeParmTypeLoc>())
              GetLocationsTemplateTypeParmTypeLoc(llvm::makeIntrusiveRefCnt<LocationCall>(Prefix,
                    "getAs<clang::TemplateTypeParmTypeLoc>", LocationCall::IsCast)
                , ConcreteTL, Locs, Rngs , TypeLocRecursionGuard);
            
            if (auto ConcreteTL = Object.getAs<clang::ObjCTypeParamTypeLoc>())
              GetLocationsObjCTypeParamTypeLoc(llvm::makeIntrusiveRefCnt<LocationCall>(Prefix,
                    "getAs<clang::ObjCTypeParamTypeLoc>", LocationCall::IsCast)
                , ConcreteTL, Locs, Rngs , TypeLocRecursionGuard);
            
            if (auto ConcreteTL = Object.getAs<clang::SubstTemplateTypeParmTypeLoc>())
              GetLocationsSubstTemplateTypeParmTypeLoc(llvm::makeIntrusiveRefCnt<LocationCall>(Prefix,
                    "getAs<clang::SubstTemplateTypeParmTypeLoc>", LocationCall::IsCast)
                , ConcreteTL, Locs, Rngs , TypeLocRecursionGuard);
            
            if (auto ConcreteTL = Object.getAs<clang::SubstTemplateTypeParmPackTypeLoc>())
              GetLocationsSubstTemplateTypeParmPackTypeLoc(llvm::makeIntrusiveRefCnt<LocationCall>(Prefix,
                    "getAs<clang::SubstTemplateTypeParmPackTypeLoc>", LocationCall::IsCast)
                , ConcreteTL, Locs, Rngs , TypeLocRecursionGuard);
            
            if (auto ConcreteTL = Object.getAs<clang::AttributedTypeLoc>())
              GetLocationsAttributedTypeLoc(llvm::makeIntrusiveRefCnt<LocationCall>(Prefix,
                    "getAs<clang::AttributedTypeLoc>", LocationCall::IsCast)
                , ConcreteTL, Locs, Rngs , TypeLocRecursionGuard);
            
            if (auto ConcreteTL = Object.getAs<clang::ObjCObjectTypeLoc>())
              GetLocationsObjCObjectTypeLoc(llvm::makeIntrusiveRefCnt<LocationCall>(Prefix,
                    "getAs<clang::ObjCObjectTypeLoc>", LocationCall::IsCast)
                , ConcreteTL, Locs, Rngs , TypeLocRecursionGuard);
            
            if (auto ConcreteTL = Object.getAs<clang::ObjCInterfaceTypeLoc>())
              GetLocationsObjCInterfaceTypeLoc(llvm::makeIntrusiveRefCnt<LocationCall>(Prefix,
                    "getAs<clang::ObjCInterfaceTypeLoc>", LocationCall::IsCast)
                , ConcreteTL, Locs, Rngs , TypeLocRecursionGuard);
            
            if (auto ConcreteTL = Object.getAs<clang::MacroQualifiedTypeLoc>())
              GetLocationsMacroQualifiedTypeLoc(llvm::makeIntrusiveRefCnt<LocationCall>(Prefix,
                    "getAs<clang::MacroQualifiedTypeLoc>", LocationCall::IsCast)
                , ConcreteTL, Locs, Rngs , TypeLocRecursionGuard);
            
            if (auto ConcreteTL = Object.getAs<clang::ParenTypeLoc>())
              GetLocationsParenTypeLoc(llvm::makeIntrusiveRefCnt<LocationCall>(Prefix,
                    "getAs<clang::ParenTypeLoc>", LocationCall::IsCast)
                , ConcreteTL, Locs, Rngs , TypeLocRecursionGuard);
            
            if (auto ConcreteTL = Object.getAs<clang::AdjustedTypeLoc>())
              GetLocationsAdjustedTypeLoc(llvm::makeIntrusiveRefCnt<LocationCall>(Prefix,
                    "getAs<clang::AdjustedTypeLoc>", LocationCall::IsCast)
                , ConcreteTL, Locs, Rngs , TypeLocRecursionGuard);
            
            if (auto ConcreteTL = Object.getAs<clang::DecayedTypeLoc>())
              GetLocationsDecayedTypeLoc(llvm::makeIntrusiveRefCnt<LocationCall>(Prefix,
                    "getAs<clang::DecayedTypeLoc>", LocationCall::IsCast)
                , ConcreteTL, Locs, Rngs , TypeLocRecursionGuard);
            
            if (auto ConcreteTL = Object.getAs<clang::PointerTypeLoc>())
              GetLocationsPointerTypeLoc(llvm::makeIntrusiveRefCnt<LocationCall>(Prefix,
                    "getAs<clang::PointerTypeLoc>", LocationCall::IsCast)
                , ConcreteTL, Locs, Rngs , TypeLocRecursionGuard);
            
    if (auto ConcreteTL = Object.getAs<clang::PointerLikeTypeLoc<clang::PointerTypeLoc, clang::PointerType, clang::PointerLikeLocInfo>>())
      GetLocationsPointerLikeTypeLoc(llvm::makeIntrusiveRefCnt<LocationCall>(Prefix,
                    "getAs<clang::PointerTypeLoc>", LocationCall::IsCast)
                , ConcreteTL, Locs, Rngs , TypeLocRecursionGuard);
    
            if (auto ConcreteTL = Object.getAs<clang::BlockPointerTypeLoc>())
              GetLocationsBlockPointerTypeLoc(llvm::makeIntrusiveRefCnt<LocationCall>(Prefix,
                    "getAs<clang::BlockPointerTypeLoc>", LocationCall::IsCast)
                , ConcreteTL, Locs, Rngs , TypeLocRecursionGuard);
            
    if (auto ConcreteTL = Object.getAs<clang::PointerLikeTypeLoc<clang::BlockPointerTypeLoc, clang::BlockPointerType, clang::PointerLikeLocInfo>>())
      GetLocationsPointerLikeTypeLoc(llvm::makeIntrusiveRefCnt<LocationCall>(Prefix,
                    "getAs<clang::BlockPointerTypeLoc>", LocationCall::IsCast)
                , ConcreteTL, Locs, Rngs , TypeLocRecursionGuard);
    
            if (auto ConcreteTL = Object.getAs<clang::MemberPointerTypeLoc>())
              GetLocationsMemberPointerTypeLoc(llvm::makeIntrusiveRefCnt<LocationCall>(Prefix,
                    "getAs<clang::MemberPointerTypeLoc>", LocationCall::IsCast)
                , ConcreteTL, Locs, Rngs , TypeLocRecursionGuard);
            
    if (auto ConcreteTL = Object.getAs<clang::PointerLikeTypeLoc<clang::MemberPointerTypeLoc, clang::MemberPointerType, clang::MemberPointerLocInfo>>())
      GetLocationsPointerLikeTypeLoc(llvm::makeIntrusiveRefCnt<LocationCall>(Prefix,
                    "getAs<clang::MemberPointerTypeLoc>", LocationCall::IsCast)
                , ConcreteTL, Locs, Rngs , TypeLocRecursionGuard);
    
            if (auto ConcreteTL = Object.getAs<clang::ObjCObjectPointerTypeLoc>())
              GetLocationsObjCObjectPointerTypeLoc(llvm::makeIntrusiveRefCnt<LocationCall>(Prefix,
                    "getAs<clang::ObjCObjectPointerTypeLoc>", LocationCall::IsCast)
                , ConcreteTL, Locs, Rngs , TypeLocRecursionGuard);
            
    if (auto ConcreteTL = Object.getAs<clang::PointerLikeTypeLoc<clang::ObjCObjectPointerTypeLoc, clang::ObjCObjectPointerType, clang::PointerLikeLocInfo>>())
      GetLocationsPointerLikeTypeLoc(llvm::makeIntrusiveRefCnt<LocationCall>(Prefix,
                    "getAs<clang::ObjCObjectPointerTypeLoc>", LocationCall::IsCast)
                , ConcreteTL, Locs, Rngs , TypeLocRecursionGuard);
    
            if (auto ConcreteTL = Object.getAs<clang::ReferenceTypeLoc>())
              GetLocationsReferenceTypeLoc(llvm::makeIntrusiveRefCnt<LocationCall>(Prefix,
                    "getAs<clang::ReferenceTypeLoc>", LocationCall::IsCast)
                , ConcreteTL, Locs, Rngs , TypeLocRecursionGuard);
            
    if (auto ConcreteTL = Object.getAs<clang::PointerLikeTypeLoc<clang::ReferenceTypeLoc, clang::ReferenceType, clang::PointerLikeLocInfo>>())
      GetLocationsPointerLikeTypeLoc(llvm::makeIntrusiveRefCnt<LocationCall>(Prefix,
                    "getAs<clang::ReferenceTypeLoc>", LocationCall::IsCast)
                , ConcreteTL, Locs, Rngs , TypeLocRecursionGuard);
    
            if (auto ConcreteTL = Object.getAs<clang::LValueReferenceTypeLoc>())
              GetLocationsLValueReferenceTypeLoc(llvm::makeIntrusiveRefCnt<LocationCall>(Prefix,
                    "getAs<clang::LValueReferenceTypeLoc>", LocationCall::IsCast)
                , ConcreteTL, Locs, Rngs , TypeLocRecursionGuard);
            
            if (auto ConcreteTL = Object.getAs<clang::RValueReferenceTypeLoc>())
              GetLocationsRValueReferenceTypeLoc(llvm::makeIntrusiveRefCnt<LocationCall>(Prefix,
                    "getAs<clang::RValueReferenceTypeLoc>", LocationCall::IsCast)
                , ConcreteTL, Locs, Rngs , TypeLocRecursionGuard);
            
            if (auto ConcreteTL = Object.getAs<clang::FunctionTypeLoc>())
              GetLocationsFunctionTypeLoc(llvm::makeIntrusiveRefCnt<LocationCall>(Prefix,
                    "getAs<clang::FunctionTypeLoc>", LocationCall::IsCast)
                , ConcreteTL, Locs, Rngs , TypeLocRecursionGuard);
            
            if (auto ConcreteTL = Object.getAs<clang::FunctionProtoTypeLoc>())
              GetLocationsFunctionProtoTypeLoc(llvm::makeIntrusiveRefCnt<LocationCall>(Prefix,
                    "getAs<clang::FunctionProtoTypeLoc>", LocationCall::IsCast)
                , ConcreteTL, Locs, Rngs , TypeLocRecursionGuard);
            
            if (auto ConcreteTL = Object.getAs<clang::FunctionNoProtoTypeLoc>())
              GetLocationsFunctionNoProtoTypeLoc(llvm::makeIntrusiveRefCnt<LocationCall>(Prefix,
                    "getAs<clang::FunctionNoProtoTypeLoc>", LocationCall::IsCast)
                , ConcreteTL, Locs, Rngs , TypeLocRecursionGuard);
            
            if (auto ConcreteTL = Object.getAs<clang::ArrayTypeLoc>())
              GetLocationsArrayTypeLoc(llvm::makeIntrusiveRefCnt<LocationCall>(Prefix,
                    "getAs<clang::ArrayTypeLoc>", LocationCall::IsCast)
                , ConcreteTL, Locs, Rngs , TypeLocRecursionGuard);
            
            if (auto ConcreteTL = Object.getAs<clang::ConstantArrayTypeLoc>())
              GetLocationsConstantArrayTypeLoc(llvm::makeIntrusiveRefCnt<LocationCall>(Prefix,
                    "getAs<clang::ConstantArrayTypeLoc>", LocationCall::IsCast)
                , ConcreteTL, Locs, Rngs , TypeLocRecursionGuard);
            
            if (auto ConcreteTL = Object.getAs<clang::IncompleteArrayTypeLoc>())
              GetLocationsIncompleteArrayTypeLoc(llvm::makeIntrusiveRefCnt<LocationCall>(Prefix,
                    "getAs<clang::IncompleteArrayTypeLoc>", LocationCall::IsCast)
                , ConcreteTL, Locs, Rngs , TypeLocRecursionGuard);
            
            if (auto ConcreteTL = Object.getAs<clang::DependentSizedArrayTypeLoc>())
              GetLocationsDependentSizedArrayTypeLoc(llvm::makeIntrusiveRefCnt<LocationCall>(Prefix,
                    "getAs<clang::DependentSizedArrayTypeLoc>", LocationCall::IsCast)
                , ConcreteTL, Locs, Rngs , TypeLocRecursionGuard);
            
            if (auto ConcreteTL = Object.getAs<clang::VariableArrayTypeLoc>())
              GetLocationsVariableArrayTypeLoc(llvm::makeIntrusiveRefCnt<LocationCall>(Prefix,
                    "getAs<clang::VariableArrayTypeLoc>", LocationCall::IsCast)
                , ConcreteTL, Locs, Rngs , TypeLocRecursionGuard);
            
            if (auto ConcreteTL = Object.getAs<clang::TemplateSpecializationTypeLoc>())
              GetLocationsTemplateSpecializationTypeLoc(llvm::makeIntrusiveRefCnt<LocationCall>(Prefix,
                    "getAs<clang::TemplateSpecializationTypeLoc>", LocationCall::IsCast)
                , ConcreteTL, Locs, Rngs , TypeLocRecursionGuard);
            
            if (auto ConcreteTL = Object.getAs<clang::DependentAddressSpaceTypeLoc>())
              GetLocationsDependentAddressSpaceTypeLoc(llvm::makeIntrusiveRefCnt<LocationCall>(Prefix,
                    "getAs<clang::DependentAddressSpaceTypeLoc>", LocationCall::IsCast)
                , ConcreteTL, Locs, Rngs , TypeLocRecursionGuard);
            
            if (auto ConcreteTL = Object.getAs<clang::VectorTypeLoc>())
              GetLocationsVectorTypeLoc(llvm::makeIntrusiveRefCnt<LocationCall>(Prefix,
                    "getAs<clang::VectorTypeLoc>", LocationCall::IsCast)
                , ConcreteTL, Locs, Rngs , TypeLocRecursionGuard);
            
            if (auto ConcreteTL = Object.getAs<clang::DependentVectorTypeLoc>())
              GetLocationsDependentVectorTypeLoc(llvm::makeIntrusiveRefCnt<LocationCall>(Prefix,
                    "getAs<clang::DependentVectorTypeLoc>", LocationCall::IsCast)
                , ConcreteTL, Locs, Rngs , TypeLocRecursionGuard);
            
            if (auto ConcreteTL = Object.getAs<clang::ExtVectorTypeLoc>())
              GetLocationsExtVectorTypeLoc(llvm::makeIntrusiveRefCnt<LocationCall>(Prefix,
                    "getAs<clang::ExtVectorTypeLoc>", LocationCall::IsCast)
                , ConcreteTL, Locs, Rngs , TypeLocRecursionGuard);
            
            if (auto ConcreteTL = Object.getAs<clang::DependentSizedExtVectorTypeLoc>())
              GetLocationsDependentSizedExtVectorTypeLoc(llvm::makeIntrusiveRefCnt<LocationCall>(Prefix,
                    "getAs<clang::DependentSizedExtVectorTypeLoc>", LocationCall::IsCast)
                , ConcreteTL, Locs, Rngs , TypeLocRecursionGuard);
            
            if (auto ConcreteTL = Object.getAs<clang::MatrixTypeLoc>())
              GetLocationsMatrixTypeLoc(llvm::makeIntrusiveRefCnt<LocationCall>(Prefix,
                    "getAs<clang::MatrixTypeLoc>", LocationCall::IsCast)
                , ConcreteTL, Locs, Rngs , TypeLocRecursionGuard);
            
            if (auto ConcreteTL = Object.getAs<clang::ConstantMatrixTypeLoc>())
              GetLocationsConstantMatrixTypeLoc(llvm::makeIntrusiveRefCnt<LocationCall>(Prefix,
                    "getAs<clang::ConstantMatrixTypeLoc>", LocationCall::IsCast)
                , ConcreteTL, Locs, Rngs , TypeLocRecursionGuard);
            
            if (auto ConcreteTL = Object.getAs<clang::DependentSizedMatrixTypeLoc>())
              GetLocationsDependentSizedMatrixTypeLoc(llvm::makeIntrusiveRefCnt<LocationCall>(Prefix,
                    "getAs<clang::DependentSizedMatrixTypeLoc>", LocationCall::IsCast)
                , ConcreteTL, Locs, Rngs , TypeLocRecursionGuard);
            
            if (auto ConcreteTL = Object.getAs<clang::ComplexTypeLoc>())
              GetLocationsComplexTypeLoc(llvm::makeIntrusiveRefCnt<LocationCall>(Prefix,
                    "getAs<clang::ComplexTypeLoc>", LocationCall::IsCast)
                , ConcreteTL, Locs, Rngs , TypeLocRecursionGuard);
            
            if (auto ConcreteTL = Object.getAs<clang::TypeOfExprTypeLoc>())
              GetLocationsTypeOfExprTypeLoc(llvm::makeIntrusiveRefCnt<LocationCall>(Prefix,
                    "getAs<clang::TypeOfExprTypeLoc>", LocationCall::IsCast)
                , ConcreteTL, Locs, Rngs , TypeLocRecursionGuard);
            
    if (auto ConcreteTL = Object.getAs<clang::TypeofLikeTypeLoc<clang::TypeOfExprTypeLoc, clang::TypeOfExprType, clang::TypeOfExprTypeLocInfo>>())
      GetLocationsTypeofLikeTypeLoc(llvm::makeIntrusiveRefCnt<LocationCall>(Prefix,
                    "getAs<clang::TypeOfExprTypeLoc>", LocationCall::IsCast)
                , ConcreteTL, Locs, Rngs , TypeLocRecursionGuard);
    
            if (auto ConcreteTL = Object.getAs<clang::TypeOfTypeLoc>())
              GetLocationsTypeOfTypeLoc(llvm::makeIntrusiveRefCnt<LocationCall>(Prefix,
                    "getAs<clang::TypeOfTypeLoc>", LocationCall::IsCast)
                , ConcreteTL, Locs, Rngs , TypeLocRecursionGuard);
            
    if (auto ConcreteTL = Object.getAs<clang::TypeofLikeTypeLoc<clang::TypeOfTypeLoc, clang::TypeOfType, clang::TypeOfTypeLocInfo>>())
      GetLocationsTypeofLikeTypeLoc(llvm::makeIntrusiveRefCnt<LocationCall>(Prefix,
                    "getAs<clang::TypeOfTypeLoc>", LocationCall::IsCast)
                , ConcreteTL, Locs, Rngs , TypeLocRecursionGuard);
    
            if (auto ConcreteTL = Object.getAs<clang::DecltypeTypeLoc>())
              GetLocationsDecltypeTypeLoc(llvm::makeIntrusiveRefCnt<LocationCall>(Prefix,
                    "getAs<clang::DecltypeTypeLoc>", LocationCall::IsCast)
                , ConcreteTL, Locs, Rngs , TypeLocRecursionGuard);
            
            if (auto ConcreteTL = Object.getAs<clang::UnaryTransformTypeLoc>())
              GetLocationsUnaryTransformTypeLoc(llvm::makeIntrusiveRefCnt<LocationCall>(Prefix,
                    "getAs<clang::UnaryTransformTypeLoc>", LocationCall::IsCast)
                , ConcreteTL, Locs, Rngs , TypeLocRecursionGuard);
            
            if (auto ConcreteTL = Object.getAs<clang::DeducedTypeLoc>())
              GetLocationsDeducedTypeLoc(llvm::makeIntrusiveRefCnt<LocationCall>(Prefix,
                    "getAs<clang::DeducedTypeLoc>", LocationCall::IsCast)
                , ConcreteTL, Locs, Rngs , TypeLocRecursionGuard);
            
            if (auto ConcreteTL = Object.getAs<clang::AutoTypeLoc>())
              GetLocationsAutoTypeLoc(llvm::makeIntrusiveRefCnt<LocationCall>(Prefix,
                    "getAs<clang::AutoTypeLoc>", LocationCall::IsCast)
                , ConcreteTL, Locs, Rngs , TypeLocRecursionGuard);
            
            if (auto ConcreteTL = Object.getAs<clang::DeducedTemplateSpecializationTypeLoc>())
              GetLocationsDeducedTemplateSpecializationTypeLoc(llvm::makeIntrusiveRefCnt<LocationCall>(Prefix,
                    "getAs<clang::DeducedTemplateSpecializationTypeLoc>", LocationCall::IsCast)
                , ConcreteTL, Locs, Rngs , TypeLocRecursionGuard);
            
            if (auto ConcreteTL = Object.getAs<clang::ElaboratedTypeLoc>())
              GetLocationsElaboratedTypeLoc(llvm::makeIntrusiveRefCnt<LocationCall>(Prefix,
                    "getAs<clang::ElaboratedTypeLoc>", LocationCall::IsCast)
                , ConcreteTL, Locs, Rngs , TypeLocRecursionGuard);
            
            if (auto ConcreteTL = Object.getAs<clang::DependentNameTypeLoc>())
              GetLocationsDependentNameTypeLoc(llvm::makeIntrusiveRefCnt<LocationCall>(Prefix,
                    "getAs<clang::DependentNameTypeLoc>", LocationCall::IsCast)
                , ConcreteTL, Locs, Rngs , TypeLocRecursionGuard);
            
            if (auto ConcreteTL = Object.getAs<clang::DependentTemplateSpecializationTypeLoc>())
              GetLocationsDependentTemplateSpecializationTypeLoc(llvm::makeIntrusiveRefCnt<LocationCall>(Prefix,
                    "getAs<clang::DependentTemplateSpecializationTypeLoc>", LocationCall::IsCast)
                , ConcreteTL, Locs, Rngs , TypeLocRecursionGuard);
            
            if (auto ConcreteTL = Object.getAs<clang::PackExpansionTypeLoc>())
              GetLocationsPackExpansionTypeLoc(llvm::makeIntrusiveRefCnt<LocationCall>(Prefix,
                    "getAs<clang::PackExpansionTypeLoc>", LocationCall::IsCast)
                , ConcreteTL, Locs, Rngs , TypeLocRecursionGuard);
            
            if (auto ConcreteTL = Object.getAs<clang::AtomicTypeLoc>())
              GetLocationsAtomicTypeLoc(llvm::makeIntrusiveRefCnt<LocationCall>(Prefix,
                    "getAs<clang::AtomicTypeLoc>", LocationCall::IsCast)
                , ConcreteTL, Locs, Rngs , TypeLocRecursionGuard);
            
            if (auto ConcreteTL = Object.getAs<clang::PipeTypeLoc>())
              GetLocationsPipeTypeLoc(llvm::makeIntrusiveRefCnt<LocationCall>(Prefix,
                    "getAs<clang::PipeTypeLoc>", LocationCall::IsCast)
                , ConcreteTL, Locs, Rngs , TypeLocRecursionGuard);
            
            if (auto ConcreteTL = Object.getAs<clang::BitIntTypeLoc>())
              GetLocationsBitIntTypeLoc(llvm::makeIntrusiveRefCnt<LocationCall>(Prefix,
                    "getAs<clang::BitIntTypeLoc>", LocationCall::IsCast)
                , ConcreteTL, Locs, Rngs , TypeLocRecursionGuard);
            
            if (auto ConcreteTL = Object.getAs<clang::DependentBitIntTypeLoc>())
              GetLocationsDependentBitIntTypeLoc(llvm::makeIntrusiveRefCnt<LocationCall>(Prefix,
                    "getAs<clang::DependentBitIntTypeLoc>", LocationCall::IsCast)
                , ConcreteTL, Locs, Rngs , TypeLocRecursionGuard);
            }
NodeLocationAccessors NodeIntrospection::GetLocations(clang::TypeLoc const &Object) {
  NodeLocationAccessors Result;
  SharedLocationCall Prefix;
  std::vector<clang::TypeLoc> TypeLocRecursionGuard;

  GetLocationsImpl(Prefix, Object, Result.LocationAccessors,
                   Result.RangeAccessors, TypeLocRecursionGuard);
return Result; }NodeLocationAccessors NodeIntrospection::GetLocations(clang::DynTypedNode const &Node){
    if (const auto *N = Node.get<CXXBaseSpecifier>())
    
      return GetLocations(const_cast<CXXBaseSpecifier *>(N));
    if (const auto *N = Node.get<CXXCtorInitializer>())
    
      return GetLocations(const_cast<CXXCtorInitializer *>(N));
    if (const auto *N = Node.get<Decl>())
    
      return GetLocations(const_cast<Decl *>(N));
    if (const auto *N = Node.get<NestedNameSpecifierLoc>())
    
      return GetLocations(*const_cast<NestedNameSpecifierLoc *>(N));
    if (const auto *N = Node.get<Stmt>())
    
      return GetLocations(const_cast<Stmt *>(N));
    if (const auto *N = Node.get<TemplateArgumentLoc>())
    
      return GetLocations(*const_cast<TemplateArgumentLoc *>(N));
    if (const auto *N = Node.get<TypeLoc>())
    
      return GetLocations(*const_cast<TypeLoc *>(N));
return {}; }
  }
}
