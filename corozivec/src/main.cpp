#include "clang/AST/Decl.h"
#include <clang/AST/RecursiveASTVisitor.h>
#include <clang/Frontend/ASTConsumers.h>
#include <clang/Frontend/CompilerInstance.h>
#include <clang/Frontend/FrontendActions.h>
#include <clang/Tooling/CommonOptionsParser.h>
#include <clang/Tooling/Tooling.h>
#include <llvm/Support/CommandLine.h> 
#include <memory>

using namespace clang::tooling;
using namespace llvm;

// Function part

class FunctionVisitor : public clang::RecursiveASTVisitor<FunctionVisitor> {
  public:
    bool VisitFunctionDecl(clang::FunctionDecl* F) {
      if (F->hasBody()) {
        llvm::outs() << "Function: " << F->getNameAsString() << "\n";
      }
      return true;
    }
};

class FunctionConsumer : public clang::ASTConsumer {
  private:
    FunctionVisitor Visitor;

  public:
    void HandleTranslationUnit(clang::ASTContext& Context) override {
      Visitor.TraverseDecl(Context.getTranslationUnitDecl());
    }
};

class FunctionAction: public clang::ASTFrontendAction {
  protected:
    std::unique_ptr<clang::ASTConsumer> CreateASTConsumer(
        clang::CompilerInstance& CI, llvm::StringRef file) override {
      return std::make_unique<FunctionConsumer>();
    }
};

static cl::OptionCategory CoroziveCategory("corozive-options");

int main(int argc, const char** argv) {
  auto ExpectedParser = CommonOptionsParser::create(argc, argv, CoroziveCategory);
  if (!ExpectedParser) {
    llvm::errs() << ExpectedParser.takeError();
    return 1;
  }

  CommonOptionsParser& OptionsParser = ExpectedParser.get();
  FixedCompilationDatabase Compilations(".", { "-x" "c", "-std=c99" });

  ClangTool Corozivec(Compilations, OptionsParser.getSourcePathList());
  return Corozivec.run(newFrontendActionFactory<FunctionAction>().get());
}
