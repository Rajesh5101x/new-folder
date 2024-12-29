class animal{
    String name;
    String food;
    public void print(){
        System.out.println(this.name +" "+ this.food);
        System.out.println(this.food);
    }
    animal(String name, String food){
        System.out.println("Animal "+name+" is created");
        this.name = name;
        this.food = food;
    }
}

public class LCS {
        public static void main (String[] args){
            animal tiger = new animal("tiger","meat");
            
            tiger.print();
        }   
}
    
    
    

