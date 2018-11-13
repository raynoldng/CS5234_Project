make all
echo "NAIVE"
./fw_naive < datasets/1024.txt
./fw_naive < datasets/2048.txt
./fw_naive < datasets/4096.txt
./fw_naive < datasets/8192.txt

echo "BLOCKING"
./fw_blocking < datasets/1024.txt
./fw_blocking < datasets/2048.txt
./fw_blocking < datasets/4096.txt
./fw_blocking < datasets/8192.txt
