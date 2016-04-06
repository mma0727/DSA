class Vehicle {
 public void getName() {
  System.out.println("Vehicle");
} }
class Car extends Vehicle {
 public void getName() {
  System.out.println("Car");
 }
 public static void hasWheels() {
  System.out.println("It has four wheels");
 } }                                                                                                                                                                                            
 class sample {
 public static void main (String[] args) {                                                                                                                                      
  Vehicle obj = new Car();                                                                                                                                           
  //What is the ouput for each line?
  obj.getName();
  ((Car)obj).getName(); 
  ((Car)obj).hasWheels();  
  obj.hasWheels();  
 } }
 
 //Vehicle
 //Car
 
 //Car
 //It has four wheels
 //It has four wheels