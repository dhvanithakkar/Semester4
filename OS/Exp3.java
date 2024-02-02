class BusTicketReservationSystem 
{
    private int seatsLeft;

    public BusTicketReservationSystem(int seatsLeft) 
    {
        this.seatsLeft = seatsLeft;
    }
    
    // Synchronized
    // public synchronized void bookSeat() throws InterruptedException 
    // {
    //     if (seatsLeft > 0) 
    //     {
    //         Thread.sleep(1000);
    //         seatsLeft--;
    //         System.out.println("Seat booked. Remaining seats: " + seatsLeft);
    //     } 
    //     else 
    //     {
    //         System.out.println("No seats available.");
    //     }
    // }

    // Not synchronized
    public void bookSeat() throws InterruptedException 
    {
            if (seatsLeft > 0) 
            {
                Thread.sleep(1000);
                seatsLeft--;
                System.out.println("Seat booked. Remaining seats: " + seatsLeft);
            } 
            else 
            {
                System.out.println("No seats available.");
            }
        }

}

class UserThread extends Thread 
{
    private BusTicketReservationSystem reservationSystem;

    public UserThread(BusTicketReservationSystem reservationSystem, String name) 
    {
        super(name);
        this.reservationSystem = reservationSystem;
    }

    public void run() 
    {
        try 
        {
            reservationSystem.bookSeat();
        } 
        catch (InterruptedException e) 
        {
            e.printStackTrace();
        }
    }
}

public class ps1 
{
    public static void main(String[] args) 
    {
        BusTicketReservationSystem reservationSystem = new BusTicketReservationSystem(1);

        UserThread user1 = new UserThread(reservationSystem, "User 1");
        UserThread user2 = new UserThread(reservationSystem, "User 2");

        user1.start();
        user2.start();
    }
}
