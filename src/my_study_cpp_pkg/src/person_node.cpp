#include "rclcpp/rclcpp.hpp"
#include "string"

class PersonNode : public rclcpp::Node
{
private:
    std::string name_;
    int age;
public:
    PersonNode(const std::string &node_name,
    const std::string &name,
    int age) : Node(node_name)
    {
        this->name_ = name;
        this->age = age;
    }

    void eat(const std::string &food)
    {
        RCLCPP_INFO(this->get_logger(), "我是%s,我今年%d岁了,我正在吃%s",
         this->name_.c_str(),
         this->age,
         food.c_str());
    }
};

int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<PersonNode>("person_node", "张三", 18);
    node->eat("面包");
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}