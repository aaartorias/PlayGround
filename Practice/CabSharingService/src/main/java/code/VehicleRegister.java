package main.java.code;

import java.util.Hashtable;

public class VehicleRegister {

    private static VehicleRegister instance = null;
    public Hashtable<String, VehicleInfo> vehicleRegister = null;

    private VehicleRegister() {
        vehicleRegister = new Hashtable<String, VehicleInfo>();
    }

    public static VehicleRegister getInstance() {

        if (instance == null) {
            synchronized (VehicleRegister.class) {
                if (instance == null) {
                    instance = new VehicleRegister();
                }
            }
        }
        return instance;
    }

}
