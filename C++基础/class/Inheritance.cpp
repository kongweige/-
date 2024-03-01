#include <iostream>

// 基类
class LanguageBase
{
public:
  LanguageBase() { };
  LanguageBase(std::string name, int age) : name_(name), age_(age) {}
  ~LanguageBase() { };

  void setName(std::string name) { name_ = name;}  
  void setAge(int age) { age_ = age; }  
  
  std::string getName() const { return name_; }  
  int getAge() const { return age_; }

private:
  std::string name_;
  int age_;
};

// 子类
class LanguageCpp : public LanguageBase
{
public:
  LanguageCpp();
  ~LanguageCpp();

private:
  std::string founder_;
  
};