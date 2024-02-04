class BusReservationSystem {
    private static int availableSeats = 1;

    // // unsynchronized, inconsistent
    // public void reserveSeat(String passengerName) {
    //     if (availableSeats > 0) {
    //         System.out.println(passengerName + " booked a seat.");
    //         availableSeats--;
    //         System.out.println("Available seats: " + availableSeats);
    //     } else {
    //         System.out.println(passengerName + " couldn't book a seat. No seats available.");
    //     }
    // }

    // synchronized, consistent
    public synchronized void reserveSeat(String passengerName) {
        if (availableSeats > 0) {
            System.out.println(passengerName + " booked a seat.");
            availableSeats--;
            System.out.println("Available seats: " + availableSeats);
        } else {
            System.out.println(passengerName + " couldn't book a seat. No seats available.");
        }
    }
}

class PassengerThread extends Thread {
    private BusReservationSystem reservationSystem;
    private String passengerName;

    public PassengerThread(BusReservationSystem reservationSystem, String passengerName) {
        this.reservationSystem = reservationSystem;
        this.passengerName = passengerName;
    }

    public void run() {
        reservationSystem.reserveSeat(passengerName);
    }
}

public class BusReservation {
    public static void main(String[] args) {
        System.err.println("Synchronized:");
        BusReservationSystem reservationSystem = new BusReservationSystem();

        PassengerThread user1 = new PassengerThread(reservationSystem, "User1");
        PassengerThread user2 = new PassengerThread(reservationSystem, "User2");

        user1.start();
        user2.start();
    }
}
