#pragma once 
#include <iostream>
class BaseAST{
public: 
    virtual ~BaseAST() = default;
    
    virtual void Dump() const = 0;
    virtual std::string PrintKoopaIR() const = 0;
};


class CompUnitAST : public BaseAST{
public:
    std::unique_ptr<BaseAST> func_def;

    void Dump() const override {
        std::cout << "CompUnitAST { ";
        func_def->Dump();
        std::cout << " }";
    }

    std::string PrintKoopaIR() const override {
        return "fun " + func_def->PrintKoopaIR();
    }

};

class FuncDefAST : public BaseAST{
public:
    std::unique_ptr<BaseAST> func_type;
    std::string ident;
    std::unique_ptr<BaseAST> block;

    void Dump() const override {
        std::cout << "FuncDefAST { ";
        func_type->Dump();
        std::cout << ", " << ident << ", ";
        block->Dump();
        std::cout << " }";
    }

    std::string PrintKoopaIR() const override {
        // std::cout << "@" << ident << "(): ";
        // func_type->PrintKoopaIR();
        // block->PrintKoopaIR();

        return "@" + ident + "(): " + func_type->PrintKoopaIR() + block->PrintKoopaIR();
    }
};

class FuncTypeAST : public BaseAST{
public:
    std::string func_type;

    void Dump() const override {
        std::cout << "FuncTypeAST { ";
        std::cout << func_type;
        std::cout << " }";
    }

    std::string PrintKoopaIR() const override {
        //std::cout << "i32 ";
        return "i32";
    }
};

class BlockAST : public BaseAST{
public:
    std::unique_ptr<BaseAST> stmt;

    void Dump() const override {
        std::cout << "BlockAST { ";
        stmt->Dump();
        std::cout << " }";
    }

    std::string PrintKoopaIR() const override {
        // std::cout << "{" << std::endl;
        // stmt->PrintKoopaIR();
        // std::cout << "}" << std::endl;

        return "{\n" + stmt->PrintKoopaIR() + "}\n";
    }
};

class StmtAST : public BaseAST{
public:
    int number;

    void Dump() const override {
        std::cout << "StmtAST { ";
        std::cout << number;
        std::cout << "}";
    }

    std::string PrintKoopaIR() const override {
        // std::cout << "\%entry:" << std::endl;
        // std::cout << "  ret " << number << std::endl; 

        return "\%entry:\n  ret " + std::to_string(number) + "\n";
        
    }
};
