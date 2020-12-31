package main.java.code;

import java.util.Hashtable;

public class UserRegister {
    private static UserRegister instance = null;
    public Hashtable<String, UserInfo> userRegister = null;

    private UserRegister() {
        userRegister = new Hashtable<String, UserInfo>();
    }

    public static UserRegister getInstance() {

        if (instance == null) {
            synchronized (UserRegister.class) {
                if (instance == null) {
                    instance = new UserRegister();
                }
            }
        }
        return instance;
    }

}