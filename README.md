# Projekt zaliczeniowy z kursu "Systemy Operacyjne 2"

## Nazwa tematu:
Lotnisko (od strony obsługi pasażerów)


## Opis wątków i zasobów:

**Wątki**: Samochody, pasażerowie, samoloty, ochroniarze

**Zasoby**: Samochody, bramki, samoloty, ochroniarze

**Ilość**: dużo pasażerów, dużo samochodów, kilka ochroniarzy, kilka samolotów, kilkanaście bramek


## Opis działania:
Aplikacja będzie symulacją lotniska od strony obsługi pasażerów.
### Czynności wykonywane dla pasażera:
1. Pasażer zostaje przywieziony samochodem i gdy podjedzie do wejścia na lotnisko, wysiada z niego.
2. Pasażer idzie w kierunku bramek. Na tym etapie może on zostać sprawdzony przez ochroniarza.
3. Pasażer oczekuje na przejście przez bramkę i przechodzi.
4. Pasażer oczekuje na samolot i wsiada do niego
5. Pasażer po odbytym locie wysiada z samolotu i kieruje się do wyjścia. Na tym etapie może on zostać sprawdzony przez ochroniarza.
6. Pasażer wychodzi z lotniska i wsiada do samochodu

### Czynności wykonywane przez samochody:
1. Przywozi pasażera pod wejście na lotnisko
2. Zabiera drugiego pasażera spod wyjścia z lotniska

### Czynności wykonywane przez samoloty:
1. Samolot oczekuje na określoną ilość pasażerów lub do końca czasu oczekiwania
2. Samolot odlatuje
3. Samolot przylatuje, wysadza pasażerów
4. Oczekiwanie na przygotowanie do nast. lotu

### Czynności wykonywane przez ochroniarzy:
1. Ochroniarz zatrzymuje losowego pasażera obecnego na lotnisku i go sprawdza
2. Ochroniarz czeka losowy czas


Samochód, samolot, ochroniarz są również zasobami, które są zajmowane przez określoną ilość pasażerów (Dla samochodu i ochroniarza to jeden pasażer, dla samolotu to kilkanaście pasażerów).
Bramki to zasoby, do których ustawiają się pasażerowie i kolejno z nich korzystają
