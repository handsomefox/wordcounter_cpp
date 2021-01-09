#include "pch.h"

class character_counter {
  std::vector<std::pair<size_t, std::string>> m_counter;

  void update_counter(size_t count, const std::string &word) {
    const auto pair = std::make_pair(count, word);
    m_counter.push_back(pair);
  }

public:
  void count_string(const std::string &str) {
    size_t counter = str.length();

    const std::string special_symbols = R"(!@#$%^&*()_+=-,./?><|\][{}`~;:'")";

    for (char i : str) {
      for (char special_symbol : special_symbols) {
        if (i == special_symbol)
          counter--;
      }
    }
    update_counter(counter, str);
  }

  void print_counters() {
    for (size_t i = 0; i < m_counter.size(); ++i)
      std::cout << "Entry no." << i
                << "  Character count: " << m_counter[i].first
                << "  Sentence: " << m_counter[i].second << "\n";
  }

  std::vector<std::pair<size_t, std::string>> get_counter() const {
    return m_counter;
  }

  void print_entry(const size_t entry_number) {
    if (entry_number <= m_counter.size() - 1)
      std::cout << "Entry no." << entry_number
                << "  Character count: " << m_counter[entry_number].first
                << "  Sentence: " << m_counter[entry_number].second << "\n\n";
    else
      std::cout << "This element does not exist\n\n";
  }

  void print_for_current() {
    const size_t entry_number = m_counter.size() - 1;
    std::cout << "Entry no." << entry_number
              << "  Character count: " << m_counter[entry_number].first
              << "  Sentence: " << m_counter[entry_number].second << "\n\n";
  }
} char_counter;

std::string string_input() {
  std::string string;
  std::cout << "Enter a string: ";
  std::getline(std::cin, string);
  return string;
}

int main(const int argc, char *argv[]) {
  SetConsoleCP(1251);
  SetConsoleOutputCP(1251);

  bool is_running = true;
  size_t num = 0;

  if (argc != 1) {
    for (auto i = 1; i < argc; ++i) {
      char_counter.count_string(argv[i]);
    }
    char_counter.print_counters();
    system("pause");
    return 0;
  }

  while (is_running) {
    std::cout << "1. Count symbols in a string\n2. Print everything\n3. Print "
                 "specific entry\n0. Exit\n\n";
    int n = _getch();
    switch (n) {
    default:
      std::cout << "Invalid input\n\n";
      break;

    case '1':
      char_counter.count_string(string_input());
      char_counter.print_for_current();
      break;

    case '2':
      char_counter.print_counters();
      break;

    case '3':
      std::cout << "Enter entry no.: ";
      std::cin >> num;
      char_counter.print_entry(num);
      break;

    case '0':
      is_running = false;
      system("pause");
      break;
    }
  }
  return 0;
}
