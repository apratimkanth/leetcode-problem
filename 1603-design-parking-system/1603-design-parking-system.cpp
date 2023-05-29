class ParkingSystem {
public:
    int x;
    int y;
    int z;
    ParkingSystem(int big, int medium, int small) {
        x=big;
        y=medium;
        z=small;
    }
    
    bool addCar(int carType) {
        switch(carType)
        {
            case 1:
            if(x){
                x=x-1;
                return true;
            }
            else return false;
            break;
            case 2:
            if(y){
                y=y-1;
                return true;
            }
            else return false;
            break;
            case 3:
            if(z){
                z=z-1;
                return true;
            }
        }
        return false;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */