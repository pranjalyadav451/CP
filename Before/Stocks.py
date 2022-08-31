import math
import sys

# create a function to get average of a list of prices
def get_average(prices):
    average = 0
    for i in range(len(prices)):
        average += float(prices[i])
    return average/len(prices)

def get_top_stocks(stocks,prices):
    top_stocks = []
    for i in range(len(stocks)):
        for j in range(len(prices[i])):
            avg = get_average(prices[i])
            top_stocks.append((stocks[i],avg))
    # sort top_stocks by average price
    top_stocks.sort(key=lambda x: x[1], reverse=True)
    # get top 3 stocks
    top_stocks = top_stocks[:3]
    # get the names of the top 3 stocks
    top_stocks = [x[0] for x in top_stocks]
    return top_stocks


def closest_to_zero(numbers):
    if(numbers is None or len(numbers) == 0):
        return 0
    
    closest = sys.maxsize
    for i in range(len(numbers)):
        if abs(numbers[i]) < abs(closest):
            closest = numbers[i]
        elif numbers[i] >=0 and abs(numbers[i]) <= abs(closest):
            closest = numbers[i]
    return closest


def main():
    nbstocks = int(input())
    nbdays = int(input())
    stocks = []
    for i in range(nbstocks):
        stocks.append(input())
    prices = []
    for i in range(nbdays):
        prices.append(input())
    print(get_top_stocks(stocks,prices))
