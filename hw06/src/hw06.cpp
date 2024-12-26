#include <hw06.h>
#include <iostream>
#include <vector>
#include <stdexcept>
#include <iomanip>
#include <algorithm>

Hall create_hall(int hall_id, int rows, int seats_per_row) {
    Hall hall;
    hall.id = hall_id;
    hall.rows = rows;
    hall.seats_per_row = seats_per_row;

    for (int row = 1; row <= rows; ++row) {
        for (int number = 1; number <= seats_per_row; ++number) {
            hall.seats.push_back({row, number, false});
        }
    }

    return hall;
}

Session create_session(int session_id, const std::string& movie_title, Hall& hall) {
    return {session_id, movie_title, hall};
}

bool reserve_seat(Session& session, int row, int seat_number) {
    for (auto& seat : session.hall.seats) {
        if (seat.row == row && seat.number == seat_number) {
            if (seat.is_reserved) {
                return false;
            } else {
                seat.is_reserved = true;
                return true;
            }
        }
    }
    throw std::out_of_range("Seat not found.");
}

bool cancel_reservation(Session& session, int row, int seat_number) {
    for (auto& seat : session.hall.seats) {
        if (seat.row == row && seat.number == seat_number) {
            if (seat.is_reserved) {
                seat.is_reserved = false;
                return true;
            } else {
                return false;
            }
        }
    }
    throw std::out_of_range("Seat not found.");
}

int get_available_seats(const Hall& hall) {
    int count = 0;
    for (const auto& seat : hall.seats) {
        if (!seat.is_reserved) {
            ++count;
        }
    }
    return count;
}

void display_hall(const Hall& hall) {
    for (int row = 1; row <= hall.rows; ++row) {
        for (int number = 1; number <= hall.seats_per_row; ++number) {
            auto it = std::find_if(hall.seats.begin(), hall.seats.end(),
                                   [row, number](const Seat& seat) {
                                       return seat.row == row && seat.number == number;
                                   });

            if (it != hall.seats.end()) {
                std::cout << (it->is_reserved ? "[X]" : "[O]");
            } else {
                std::cout << "   ";
            }
        }
        std::cout << "\n";
    }
}
