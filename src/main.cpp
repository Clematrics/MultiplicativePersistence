#include <chrono>
#include <cstdint>
#include <iostream>
#include <string>

#include "mpirxx.h"

int64_t persistence(mpz_class n, int64_t steps = 0) {
	if (n < 10)
		return steps;

	mpz_class new_n = 1;
	while (n > 0) {
		new_n *= n % 10;
		n /= 10;
	}
	return persistence(new_n, steps + 1);
}

auto max_persistence(int64_t numbers) {
	int64_t max_persistence_found = -1;
	std::string max_persistence_nb(numbers, '9');
	uint64_t cnt = 0;

	for (bool is3 : {false, true}) {
		mpz_class val3 = is3 ? 3 : 1;
		int64_t rem3 = numbers - (is3 ? 1 : 0);
		for (bool is5 : {false, true}) {
			if (!is5) {
				mpz_class val35(val3);
				int64_t rem35 = rem3;
				for (int64_t cnt4 = 0; cnt4 <= rem35; cnt4++) {
					mpz_class val354(val35 * mpz_class(4).pow(cnt4));
					int64_t rem354 = rem35 - cnt4;

					std::initializer_list<bool> possibilities_for_2;
					if (rem354 == 0 || is3 || cnt4 > 0)
						possibilities_for_2 = {false};
					else
						possibilities_for_2 = {false, true};

					for (bool is2 : possibilities_for_2) {
						mpz_class val3542(val354 * (is2 ? 2 : 1));
						int64_t rem3542 = rem354 - (is2 ? 1 : 0);
						for (int64_t cnt8 = 0; cnt8 <= rem3542; cnt8++) {
							mpz_class val35428(val3542 * mpz_class(8).pow(cnt8));
							int64_t rem35428 = rem3542 - cnt8;
							for (int64_t cnt6 = 0; cnt6 <= rem35428; cnt6++) {
								mpz_class val354286(val35428 * mpz_class(6).pow(cnt6));
								int64_t rem354286 = rem35428 - cnt6;

								cnt += rem354286 + 1;
								for (int64_t cnt7 = 0; cnt7 <= rem354286; cnt7++) {
									mpz_class val3542867(val354286 * mpz_class(7).pow(cnt7));
									int64_t rem3542867 = rem354286 - cnt7;

									int64_t cnt9 = rem3542867;
									mpz_class val35428679(val3542867 * mpz_class(9).pow(cnt9));

									int64_t pers = 1 + persistence(val35428679);
									if (pers > max_persistence_found) {
										max_persistence_found = pers;
										const std::string str_nb =
												std::string(is2 ? 1 : 0, '2')
											+	std::string(is3 ? 1 : 0, '3')
											+	std::string(cnt4	, '4')
											+	std::string(cnt6	, '6')
											+	std::string(cnt7	, '7')
											+	std::string(cnt8	, '8')
											+	std::string(cnt9	, '9');
										max_persistence_nb = str_nb;
									} else if (pers == max_persistence_found) {
										const std::string str_nb =
												std::string(is2 ? 1 : 0, '2')
											+	std::string(is3 ? 1 : 0, '3')
											+	std::string(cnt4	, '4')
											+	std::string(cnt6	, '6')
											+	std::string(cnt7	, '7')
											+	std::string(cnt8	, '8')
											+	std::string(cnt9	, '9');
										if (str_nb < max_persistence_nb)
											max_persistence_nb = str_nb;
									}
								}
							}
						}
					}
				}
			} else {
				for (int64_t cnt5 = 1; cnt5 <= rem3; cnt5++) {
					mpz_class val35(val3 * mpz_class(5).pow(cnt5));
					int64_t rem35 = rem3 - cnt5;

					cnt += rem35 + 1;
					for (int64_t cnt7 = 0; cnt7 <= rem35; cnt7++) {
						mpz_class val357(val35 * mpz_class(7).pow(cnt7));
						int64_t rem357 = rem35 - cnt7;

						int64_t cnt9 = rem357;
						mpz_class val3579(val357 * mpz_class(9).pow(cnt9));

						int64_t pers = 1 + persistence(val3579);
						if (pers > max_persistence_found) {
							max_persistence_found = pers;
							const std::string str_nb =
									std::string(is3 ? 1 : 0, '3')
								+	std::string(cnt5	, '5')
								+	std::string(cnt7	, '7')
								+	std::string(cnt9	, '9');
							max_persistence_nb = str_nb;
						} else if (pers == max_persistence_found) {
							const std::string str_nb =
									std::string(is3 ? 1 : 0, '3')
								+	std::string(cnt5	, '5')
								+	std::string(cnt7	, '7')
								+	std::string(cnt9	, '9');
							if (str_nb < max_persistence_nb)
								max_persistence_nb = str_nb;
						}
					}
				}
			}
		}
	}

	return std::tuple{ max_persistence_found, max_persistence_nb, cnt };
}

uint64_t count_possibilities(int64_t numbers) {
	int64_t cnt = 0;

	for (bool is3 : {false, true}) {
		int64_t rem3 = numbers - is3;
		for (bool is5 : {false, true}) {
			if (!is5) {
				int64_t rem35 = rem3;
				for (int64_t cnt4 = 0; cnt4 <= rem35; cnt4++) {
					int64_t rem354 = rem35 - cnt4;

					std::initializer_list<bool> possibilities_for_2;
					if (rem354 == 0 || is3 || cnt4)
						possibilities_for_2 = {false};
					else
						possibilities_for_2 = {false, true};

					for (bool is2 : possibilities_for_2) {
						int64_t rem3542 = rem354 - is2;
						for (int64_t cnt8 = 0; cnt8 <= rem3542; cnt8++) {
							int64_t rem35428 = rem3542 - cnt8;
							for (int64_t cnt6 = 0; cnt6 <= rem35428; cnt6++) {
								int64_t rem354286 = rem35428 - cnt6;

								cnt += rem354286 + 1;
							}
						}
					}
				}
			} else {
				for (int64_t cnt5 = 1; cnt5 <= rem3; cnt5++) {
					int64_t rem35 = rem3 - cnt5;

					cnt += rem35 + 1;
				}
			}
		}
	}

	return cnt;
}


// NOTE : ne pas compiler avec les optimisations du compilateur microsoft activé, car sinon, donne de faux résultats. Rester avec l'option /Od
int main() {
	int from = 1, to = 20;
	std::cout << "From : ";
	std::cin >> from;
	std::cout << "To : ";
	std::cin >> to;

	std::chrono::time_point<std::chrono::system_clock> start = std::chrono::system_clock::now(), end;
	for (int i = from; i <= to; i++) {
		auto [pers, nb, cnt] = max_persistence(i);
		std::cout << "Number of digits : " << i << "; possibilites : " << cnt << "; maximum found : \t" << pers << ",\t" << nb << std::endl;
	}
	end = std::chrono::system_clock::now();
	uint64_t elapsed_seconds = std::chrono::duration_cast<std::chrono::seconds>(end - start).count();
	std::cout << "Time elapsed : " << elapsed_seconds << "s\n";

	return 0;
}