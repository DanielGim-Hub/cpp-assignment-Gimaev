#include <hw06.h>
#include <gtest/gtest.h>

TEST(Hw06Tests, Test1)
{
    auto rows = 5, seats_per_row = 8;
    Hall hall = create_hall(1, rows, seats_per_row);
    Session session = create_session(1, "Die Hard", hall);

    auto avail_seats = get_available_seats(hall);
    auto expected_seats = rows * seats_per_row;
    EXPECT_EQ(expected_seats, avail_seats);
}

TEST(Hw06Tests, Test2)
{
  auto rows = 5, seats_per_row = 15;
  Hall hall = create_hall(1, rows, seats_per_row);
  Session session = create_session(1, "Die Hard", hall);

  // reserve 2 seats
  auto reserved_seats = 2;
  reserve_seat(session, 1, 3);
  reserve_seat(session, 2, 5);

  auto avail_seats = get_available_seats(hall);
  auto expected_seats = rows * seats_per_row - reserved_seats;
  EXPECT_EQ(expected_seats, avail_seats);
}

TEST(Hw06Tests, Test3)
{
  auto rows = 3, seats_per_row = 5;
  Hall hall = create_hall(1, rows, seats_per_row);
  Session session = create_session(1, "Die Hard", hall);

  // reserve 1 seat
  reserve_seat(session, 1, 3);
  cancel_reservation(session, 1, 3);

  auto avail_seats = get_available_seats(hall);
  auto expected_seats = rows * seats_per_row;
  EXPECT_EQ(expected_seats, avail_seats);
}

TEST(Hw06Tests, Test4)
{
  auto rows = 3, seats_per_row = 5;
  Hall hall = create_hall(1, rows, seats_per_row);
  Session session = create_session(1, "Die Hard", hall);

  // reserve 1 seat
  reserve_seat(session, 1, 3);
  auto reserve_stat = reserve_seat(session, 1, 3);
  auto expected_stat = false;
  EXPECT_EQ(expected_stat, reserve_stat);
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
// Попытка отменить бронь на место, которое не было забронировано
TEST(Hw06Tests, Test5) {
    auto rows = 4, seats_per_row = 6;
    Hall hall = create_hall(1, rows, seats_per_row);
    Session session = create_session(1, "Inception", hall);

    auto cancel_stat = cancel_reservation(session, 2, 3);
    EXPECT_EQ(false, cancel_stat);
}

TEST(Hw06Tests, Test6) {
    auto rows = 3, seats_per_row = 4;
    Hall hall = create_hall(1, rows, seats_per_row);
    Session session = create_session(1, "Avatar", hall);

    // Попытка зарезервировать несуществующее место
    try {
        reserve_seat(session, 4, 2);
        FAIL() << "Expected std::out_of_range";
    } catch (const std::out_of_range& e) {
        EXPECT_STREQ("Seat not found.", e.what());
    } catch (...) {
        FAIL() << "Expected std::out_of_range";
    }
}

TEST(Hw06Tests, Test7) {
    auto rows = 5, seats_per_row = 10;
    Hall hall = create_hall(1, rows, seats_per_row);
    Session session = create_session(1, "The Matrix", hall);

    // Резервирование всех мест в зале
    for (int row = 1; row <= rows; ++row) {
        for (int number = 1; number <= seats_per_row; ++number) {
            reserve_seat(session, row, number);
        }
    }

    auto avail_seats = get_available_seats(hall);
    EXPECT_EQ(0, avail_seats);
}

TEST(Hw06Tests, Test8) {
    auto rows = 3, seats_per_row = 5;
    Hall hall = create_hall(1, rows, seats_per_row);
    Session session = create_session(1, "Interstellar", hall);

    // Попытка дважды отменить одну и ту же бронь
    reserve_seat(session, 2, 2);
    cancel_reservation(session, 2, 2);
    auto second_cancel = cancel_reservation(session, 2, 2);
    EXPECT_EQ(false, second_cancel);
}

TEST(Hw06Tests, Test9) {
    auto rows = 6, seats_per_row = 7;
    Hall hall = create_hall(1, rows, seats_per_row);
    Session session = create_session(1, "The Dark Knight", hall);

    // Проверка корректности отображения зала после бронирования
    reserve_seat(session, 1, 1);
    reserve_seat(session, 1, 2);
    reserve_seat(session, 2, 1);
    reserve_seat(session, 2, 2);

    std::cout << "Expected hall layout:\n";
    std::cout << "[X][X][O][O][O][O][O]\n"
              << "[X][X][O][O][O][O][O]\n"
              << "[O][O][O][O][O][O][O]\n"
              << "[O][O][O][O][O][O][O]\n"
              << "[O][O][O][O][O][O][O]\n"
              << "[O][O][O][O][O][O][O]\n\n";

    std::cout << "Actual hall layout:\n";
    display_hall(hall);
}
