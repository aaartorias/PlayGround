package main.java.code;

public class VehicleInfo {
    private String name;
    private String licenseId;
    private String model;
    VehicleRegister instance;

    public VehicleInfo() {}

    public VehicleInfo(String name, String model, String licenseId) {
        this.name = name;
        this.licenseId = licenseId;
        this.model = model;
        addToVehicleRegister(name, this);
    }
    public void addToVehicleRegister(String name, VehicleInfo vehicleInfo) {
        instance = VehicleRegister.getInstance();
        instance.vehicleRegister.put(name, vehicleInfo);
    }

    public void addVehicle(String name, String model, String licenseId) {
        VehicleInfo vehicleInfo = new VehicleInfo(name, licenseId, model);
    }

    public String getName() {
        return name;
    }

    public String getLicenseId() {
        return licenseId;
    }

    public String getModel() {
        return model;
    }

}
