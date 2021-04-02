char hexchars[] = "0123456789abcdef";
void convertBytesToHex(const uint8_t* bytes, uint32_t size, char* hex)
{
	while (size--)
	{
		*hex++ = hexchars[*bytes >> 4];
		*hex++ = hexchars[*bytes & 15];
		bytes++;
	}
	*hex = '\0';
}