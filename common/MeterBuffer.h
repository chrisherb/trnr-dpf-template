template <int size> class MeterBuffer {
public:
  MeterBuffer() {}
  void setSampleRate(float _sampleRate) { _sampleRate = _sampleRate; }
  void setTimeMs(float _time_ms) { time_ms = _time_ms; }

  void processSample(float sample) {
    if (counter > 0)
      counter--;

    if (counter <= 0) {
      for (int i = 0; i < size; i++) {
        if (i < size - 1)
          buffer[i] = buffer[i + 1];
      }
      buffer[size - 1] = sample;

      counter = msToSamples(time_ms);
    }
  }

private:
  float buffer[size];
  int counter = -1;
  float time_ms = 0;
  float sampleRate = 48000;

  int msToSamples(float ms) { return ms * sampleRate / 1000; }
};