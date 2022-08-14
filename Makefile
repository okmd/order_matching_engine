compile: main.o order.o limit_order.o market_order.o order_book.o exchange.o
	g++ main.o order.o limit_order.o market_order.o order_book.o exchange.o -o main

main.o: main.cpp
	g++ -c main.cpp

order.o: order.cpp
	g++ -c order.cpp

limit_order.o: limit_order.cpp
	g++ -c limit_order.cpp

market_order.o: market_order.cpp
	g++ -c market_order.cpp

order_book.o: order_book.cpp
	g++ -c order_book.cpp
	
exchange.o: exchange.cpp
	g++ -c exchange.cpp

run: 
	main

clean:
	del *.exe *.o