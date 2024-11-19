def leaky_bucket(packet_arrival_rate, bucket_capacity, output_rate):
    bucket = 0
    for i, packets in enumerate(packet_arrival_rate):
        bucket += packets
        print(f"Time {i}s - Packets received: {packets}, Bucket size: {bucket}")
        
        if bucket > bucket_capacity:
            print(f"Bucket overflow! {bucket - bucket_capacity} packets dropped.")
            bucket = bucket_capacity
        
        send = min(bucket, output_rate)
        bucket -= send
        print(f"Time {i}s - Packets sent: {send}, Remaining in bucket: {bucket}\n")
        time.sleep(1)