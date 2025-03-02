#!/usr/bin/python3
""" Making Change """

def makeChange(coins, total):
    """ 
    Determine the fewest number of coins needed to meet the given amount.

    Args:
        coins (List[int]): List of available coin values
        total (int): The total amount needed

    Returns:
        int: Fewest number of coins, or -1 if not possible
    """
    if total <= 0:
        return 0

    coins.sort(reverse=True)  # Sort coins in descending order
    num_coins = 0
    remaining = total

    for coin in coins:
        if remaining == 0:
            break
        if coin <= remaining:
            count = remaining // coin  # Use as many of this coin as possible
            num_coins += count
            remaining -= count * coin

    return num_coins if remaining == 0 else -1
