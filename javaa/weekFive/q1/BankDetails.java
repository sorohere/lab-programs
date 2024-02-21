class Bank {
    float getRateOfInterest() {
        return 0.0f; 
    }
}

class SBI extends Bank {
    @Override
    float getRateOfInterest() {
        return 8.0f; 
    }
}

class ICICI extends Bank {
    @Override
    float getRateOfInterest() {
        return 7.0f; 
    }
}

class AXIS extends Bank {
    @Override
    float getRateOfInterest() {
        return 9.0f; 
    }
}

class BankDetails {
    public static void main(String[] args) {
        Bank sbi = new SBI();
        Bank icici = new ICICI();
        Bank axis = new AXIS();

        System.out.println("SBI Bank Interest Rate: " + sbi.getRateOfInterest() + "%");
        System.out.println("ICICI Bank Interest Rate: " + icici.getRateOfInterest() + "%");
        System.out.println("AXIS Bank Interest Rate: " + axis.getRateOfInterest() + "%");
    }
}
