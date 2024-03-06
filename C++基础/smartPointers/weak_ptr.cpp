// weak_ptr
// 用来解决shared_ptr相互引用时的死锁问题，两个shared_ptr相互引用,两个指针的引用计数永远不可能下降为0,资源永远不会释放。
// weak_ptr是对对象的一种弱引用，不会增加对象的引用计数，和shared_ptr之间可以相互转化，shared_ptr可以直接赋值给它，它可以通过调用lock函数来获得shared_ptr

#include <iostream>
#include <memory>
#include <vector>

#if 0
class Post;

class User 
{
public:
  User(const std::string& name) : name_(name) 
  {
    std::cout << "User " << name << " created" << std::endl;
  }

  void addPost(const std::shared_ptr<Post>& post) 
  {
    posts_vec_.push_back(post);
  }

  ~User() 
  {
    std::cout << "User " << name_ << " destroyed" << std::endl;
  }

private:
  std::string name_;
  std::vector<std::shared_ptr<Post>> posts_vec_;
};

class Post 
{
public:
  Post(const std::string& content) : content_(content)
  {
    std::cout << "Post created with content: " << content << std::endl;
  }

  void setUser(const std::shared_ptr<User>& user) 
  {
    this->user_ = user;
  }

  ~Post() 
  {
    std::cout << "Post with content: " << content_ << " destroyed" << std::endl;
  }

private:
  std::string content_;
  std::shared_ptr<User> user_;
};

int main() 
{
  // 创建用户和帖子
  std::shared_ptr<User> user1 = std::make_shared<User>("C++");
  std::shared_ptr<User> user2 = std::make_shared<User>("Pytnon");

  std::shared_ptr<Post> post1 = std::make_shared<Post>("Hello, World!");
  std::shared_ptr<Post> post2 = std::make_shared<Post>("Goodbye!");

  // 设置用户和帖子之间的关系
  user1->addPost(post1);
  user2->addPost(post2);  

  post1->setUser(user1);
  post2->setUser(user2);  
  // 在main函数结束时，user1、user2、post1和post2的引用计数都不会变为0
  // 由于循环引用，它们的析构函数不会被调用，可能导致内存泄漏

  return 0;
}
#else 

class Post;

class User 
{
public:
  User(const std::string& name) : name_(name) 
  {
    std::cout << "User " << name << " created" << std::endl;
  }

  void addPost(const std::shared_ptr<Post>& post) 
  {
    posts_vec_.push_back(post);
  }

  ~User() 
  {
    std::cout << "User " << name_ << " destroyed" << std::endl;
  }

private:
  std::string name_;
  std::vector<std::weak_ptr<Post>> posts_vec_;
};

class Post 
{
public:
  Post(const std::string& content) : content_(content)
  {
    std::cout << "Post created with content: " << content << std::endl;
  }

  void setUser(const std::shared_ptr<User>& user) 
  {
    this->user_ = user;
  }

  ~Post() 
  {
    std::cout << "Post with content: " << content_ << " destroyed" << std::endl;
  }

private:
  std::string content_;
  std::shared_ptr<User> user_; // 帖子始终是和用户关联的 如果是weak_ptr是不合理的
};


int main()
{
  // 创建用户和帖子
  std::shared_ptr<User> user1 = std::make_shared<User>("Alice");
  std::shared_ptr<User> user2 = std::make_shared<User>("Bob");

  std::shared_ptr<Post> post1 = std::make_shared<Post>("Hello, World!");
  std::shared_ptr<Post> post2 = std::make_shared<Post>("Goodbye!");

  // 设置用户和帖子之间的关系
  user1->addPost(post1);
  user2->addPost(post2);

  post1->setUser(user1);
  post2->setUser(user2);

  // 输出每个 shared_ptr 的引用计数
  std::cout << "Reference counts at program end:" << std::endl;
  std::cout << "User1 use count: " << user1.use_count() << std::endl;
  std::cout << "User2 use count: " << user2.use_count() << std::endl;
  std::cout << "Post1 use count: " << post1.use_count() << std::endl;
  std::cout << "Post2 use count: " << post2.use_count() << std::endl;

  return 0;
}

#endif