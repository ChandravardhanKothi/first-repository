#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

int loco;

#define location 8

// Structure to hold user details
struct User
{
    char name[50];
    char phoneNumber[15];
};

// Structure to hold booking details
struct Booking
{
    char customerName[50];
    char source[50];
    char destination[50];
    float fare;
    bool isBookingConfirmed;
};

// Function prototypes
void login(struct User *user);
void bookCab(struct Booking *booking, struct User user);
void viewBookingDetails(struct Booking booking);
void cancelBooking(struct Booking *booking);
float calculateFare(float distance);
int customFunction(int parameter);
// void review
void review();

int main()
{
    struct User user;
    struct Booking booking;
    int choice;

    login(&user);
    choice = 1;
    do
    {
        printf("\nWelcome, %s!\n", user.name);
        printf("1. Book a cab\n");
        printf("2. View booking details\n");
        printf("3. Cancel booking\n");
        printf("4. Logout\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            bookCab(&booking, user);
            break;
        case 2:
            viewBookingDetails(booking);
            break;
        case 3:
            cancelBooking(&booking);
            break;
        case 4:
            review();
            printf("Logging out...\n");
            break;
        default:
            printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 4);

    return 0;
}

void login(struct User *user)
{
    printf("Please log in to continue.\n");
    printf("Enter your name: ");
    fgets(user->name, sizeof(user->name), stdin);
    user->name[strcspn(user->name, "\n")] = '\0'; // Remove trailing newline
    printf("Enter your phone number: ");
    fgets(user->phoneNumber, sizeof(user->phoneNumber), stdin);
    user->phoneNumber[strcspn(user->phoneNumber, "\n")] = '\0'; // Remove trailing newline
}

void bookCab(struct Booking *booking, struct User user)
{
    char locations[location][50] = {"Anurag University", "Pocharam", "Annojiguda", "Narapalli",
                                    "Boduppal", "Nacharam", "Uppal", "Amberpet"};

    printf("Available pickup locations:\n");
    for (int i = 0; i < location; i++)
    {
        printf("%d. %s\n", i + 1, locations[i]);
    }
    int pickupChoice, dropChoice;
    printf("Enter pickup location (1-8): ");
    scanf("%d", &pickupChoice);
    printf("Enter drop location (1-8): ");
    scanf("%d", &dropChoice);

    if (pickupChoice >= 1 && pickupChoice <= location && dropChoice >= 1 && dropChoice <= location)
    {
        strcpy(booking->customerName, user.name);
        strcpy(booking->source, locations[pickupChoice - 1]);
        strcpy(booking->destination, locations[dropChoice - 1]);
        float distance = customFunction(dropChoice);
        booking->fare = calculateFare(distance);
        booking->isBookingConfirmed = true;
        printf("Booking successful! Enjoy your ride.\n");
    }
    else
    {
        printf("Invalid location choices. Please try again.\n");
    }
}

void viewBookingDetails(struct Booking booking)
{
    if (booking.isBookingConfirmed)
    {
        printf("\nBooking Details:\n");
        printf("Customer Name: %s\n", booking.customerName);
        printf("Pickup Location: %s\n", booking.source);
        printf("Drop Location: %s\n", booking.destination);
        printf("distance between locations is : %d\n", loco);
        printf("Fare: %.2f rupees only\n", booking.fare);
    }
    else
    {
        printf("No booking details available.\n");
    }
}

void cancelBooking(struct Booking *booking)
{
    if (booking->isBookingConfirmed)
    {
        printf("Booking canceled successfully.\n");
        booking->isBookingConfirmed = false;
    }
    else
    {
        printf("No active booking to cancel.\n");
    }
}

int customFunction(int parameter)
{
    switch (parameter)
    {
    case 1:
        loco = 4;
        return 4; // No output for parameter 1
    case 2:
        loco = 40;
        return 40;
    case 3:
        loco = 8;
        return 8;
    case 4:
        loco = 10;
        return 10;
    case 5:
        loco = 11;
        return 11;
    case 6:
        loco = 14;
        return 14;
    case 7:
        loco = 12;
        return 12;
    case 8:
        loco = 17;
        return 17;
    default:
        return -1; // Invalid parameter
    }
}

float calculateFare(float distance)
{
    if (distance >= 0.0)
    {
        if (distance < 7)
        {
            return distance * 12;
        }
        else
        {
            return distance * 18;
        }
    }
    else
    {
        // If distance is invalid, return -1 indicating invalid fare
        return -1.0;
    }
}

void review()
{
    int cleanliness_rating, behavior_rating, on_time_rating, driving_experience_rating, overall_rating;
    char review[1000];

    // Asking feedback questions
    printf("Please provide feedback on the following aspects of your Ola cab ride:\n");

    // Cleanliness and hygiene rating
    printf("1. Cleanliness and hygiene (out of 5): ");
    scanf("%d", &cleanliness_rating);

    // Polite behavior rating
    printf("2. Polite behavior of the driver (out of 5): ");
    scanf("%d", &behavior_rating);

    // On-time service rating
    printf("3. On-time service (out of 5): ");
    scanf("%d", &on_time_rating);

    // Experience in driving rating
    printf("4. Experience in driving (out of 5): ");
    scanf("%d", &driving_experience_rating);

    // Review
    printf("5. Please provide a brief review of your ride experience:\n");
    scanf(" %[^\n]s", review);

    // Overall rating
    printf("6. Overall rating (out of 5): ");
    scanf("%d", &overall_rating);

    // Displaying feedback
    printf("\nThank you for providing feedback!\n");
    printf("Cleanliness and hygiene: %d/5\n", cleanliness_rating);
    printf("Polite behavior: %d/5\n", behavior_rating);
    printf("On-time service: %d/5\n", on_time_rating);
    printf("Driving experience: %d/5\n", driving_experience_rating);
    printf("Review: %s\n", review);
    printf("Overall rating: %d/5\n", overall_rating);
}
// members of the code
// chandravardhan kothi :)
// the end of the code <3