import time

# def leaky_bucket(packet_arrival_rate, bucket_capacity, output_rate):
#     bucket = 0
#     for i, packets in enumerate(packet_arrival_rate):
#         bucket += packets
#         print(f"Time {i}s - Packets received: {packets}, Bucket size: {bucket}")
        
#         if bucket > bucket_capacity:
#             print(f"Bucket overflow! {bucket - bucket_capacity} packets dropped.")
#             bucket = bucket_capacity
        
#         send = min(bucket, output_rate)
#         bucket -= send
#         print(f"Time {i}s - Packets sent: {send}, Remaining in bucket: {bucket}\n")
#         time.sleep(1)
# # Sample input data for packet arrival (packets per second)
# packet_arrival_rate = [5, 10, 15, 3, 4, 2]  # Packets arriving per second
# bucket_capacity = 20  # Max bucket capacity
# output_rate = 5  # Constant output rate per second
# leaky_bucket(packet_arrival_rate, bucket_capacity, output_rate)

# def token_bucket(packet_arrival_rate, bucket_capacity, token_rate, max_tokens):
#     tokens = 0
#     for i, packets in enumerate(packet_arrival_rate):
#         tokens = min(max_tokens, tokens + token_rate)
#         print(f"Time {i}s - Tokens available: {tokens}")
        
#         if packets <= tokens:
#             tokens -= packets
#             print(f"Time {i}s - Packets sent: {packets}, Tokens left: {tokens}\n")
#         else:
#             print(f"Time {i}s - Insufficient tokens! {packets} packets delayed or dropped.\n")
#         time.sleep(1)
# # Sample input data for packet arrival (packets per second)
# packet_arrival_rate = [5, 10, 15, 3, 4, 2]  # Packets arriving per second
# bucket_capacity = 20  # Max token capacity
# token_rate = 5  # Tokens generated per second
# max_tokens = 20  # Maximum number of tokens the bucket can hold

# token_bucket(packet_arrival_rate, bucket_capacity, token_rate, max_tokens)


import random
import time

def simulate_three_way_handshake(packet_loss_probability=0.1, latency=0.5):
    print("Simulating Three-Way Handshake...")
    steps = ["SYN", "SYN-ACK", "ACK"]
    for step in steps:
        if random.random() < packet_loss_probability:
            print(f"{step} lost! Retrying...")
            time.sleep(latency)
            print(f"{step} resent and successfully received.")
        else:
            print(f"{step} successfully sent and received.")
        time.sleep(latency)
    print("Connection Established.\n")

def simulate_four_way_handshake(packet_loss_probability=0.1, latency=0.5):
    print("Simulating Four-Way Handshake...")
    steps = ["FIN", "ACK", "FIN", "ACK"]
    for step in steps:
        if random.random() < packet_loss_probability:
            print(f"{step} lost! Retrying...")
            time.sleep(latency)
            print(f"{step} resent and successfully received.")
        else:
            print(f"{step} successfully sent and received.")
        time.sleep(latency)
    print("Connection Terminated.\n")

# Testing the simulation
simulate_three_way_handshake(packet_loss_probability=0.2, latency=1)
simulate_four_way_handshake(packet_loss_probability=0.2, latency=1)