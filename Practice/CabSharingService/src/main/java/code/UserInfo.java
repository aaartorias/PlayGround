package main.java.code;

public class UserInfo {

    private String name;
    private String gender;
    private int age;
    UserRegister instance;

    public UserInfo() {}

    void addToUserRegister(String name, UserInfo userInfo) {
        instance = UserRegister.getInstance();
        instance.userRegister.put(name, userInfo);
    }

    static void addUser(String name, String gender, int age)
    {
        UserInfo userInfo = new UserInfo(name, gender, age);
    }

    public UserInfo(String name, String gender, int age) {
        this.name = name;
        this.gender = gender;
        this.age = age;
        addToUserRegister(name, this);
    }

    public void setName(String name) {
        this.name = name;
    }

    public void setGender(String gender) {
        this.gender = gender;
    }

    public void setAge(int age) {
        this.age = age;
    }

    public String getName() {
        return name;
    }

    public String getGender() {
        return gender;
    }

    public int getAge() {
        return age;
    }

}
