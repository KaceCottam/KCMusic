#ifndef KCMUSIC_H
#define KCMUSIC_H
#include <Windows.h>
#include <string>
namespace KC
{
		static class Tone final
		{
			const int Value[58] = {
				16, 18, 20, 21, 24, 27, 30, 32, 36, 41, 43, 49, 55, 61, 65, 73, 82, 87, 98, 110, 123, 130, 146, 164, 174,
				196, 220, 246, 261, 293, 329, 349, 392, 440, 493, 523, 587, 659, 698, 783, 880, 987, 1046, 1174, 1318, 1396,
				1567, 1760, 1975, 2093, 2349, 2637, 2793, 3135, 3520, 3951, 4186, 4698 };
		public:
			int FetchTone(int row, int column, int noteOffset = 0) const;
		} tone;
		//This is not needed, it is just used for mapping to Tone::TONE_VALUES.Value
		enum class NoteTonesIndeces : int
		{
			C0 = 0, D0, E0, F0, G0, A0, B0, C1, D1, E1, F1, G1, A1, B1, C2, D2, E2, F2, G2, A2, B2, C3, D3, E3, F3, G3, A3, B3, C4,
			D4, E4, F4, G4, A4, B4, C5, D5, E5, F5, G5, A5, B5, C6, D6, E6, F6, G6, A6, B6, C7, D7, E7, F7, G7, A7, B7, C8, D8
		};
		enum class Note : char
		{
			Whole = 'W',
			Half = 'H',
			Quarter = 'Q',
			Eighth = 'E'
		};
		class MusicFile final
		{
			static auto TestFileParsing(const bool& fileStart, const bool& fileEnd, const bool& musicStart,
			                            const int& bpm, const int& baseNote) -> void;
			static auto ConvertNoteToIndex(const Note& n) -> int;
			static auto PlayNote(int noteTone, DWORD duration, DWORD sleepMilliseconds) -> void;
			auto SetLocals(const std::stringstream& buffer, const int& bpm, const int& baseNote) -> void;

			std::string Buffer;
			int WholeNoteDuration;
			int HalfNoteDuration;
			int QuarterNoteDuration;
			int EighthNoteDuration;
		public:
			static void PlayString(std::string& buffer, int timeInBetweenNotes);
			MusicFile() = delete;
			explicit MusicFile(const std::string& filename);
			explicit MusicFile(std::string&& filename);
			void ParseMusicFile(const std::string& fileName);
			auto Play(DWORD timeToWaitInBetweenNotes = 0) const -> void;
		};
}
#endif // KCMUSIC_H
