// Convert hex string to byte array
size_t hexStringToByteArray(const char* hex_str, unsigned char* byte_array, size_t byte_array_max)
{
	if (hex_str == NULL || byte_array == NULL)
		return -2;

	size_t hex_str_len = strlen(hex_str);
	int i = 0;
	int j = 0;

	// The output array size is half the hex_str length (rounded up)
	size_t byte_array_size = (hex_str_len + 1) / 2;

	if (byte_array_size > byte_array_max) {
		// Too big for the output array
		return -1;
	}

	if (hex_str_len % 2 == 1) {
		// hex_str is an odd length, so assume an implicit "0" prefix
		if (sscanf(&(hex_str[0]), "%1hhx", &(byte_array[0])) != 1) {
			return -1;
		}

		i = j = 1;
	}

	for (; i < hex_str_len; i += 2, j++) {
		if (sscanf(&(hex_str[i]), "%2hhx", &(byte_array[j])) != 1) {
			return -1;
		}
	}

	return byte_array_size;

}