import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;

public class Main {
    public static void main(String[] args) throws IOException {
        final var answer = Files.lines(Path.of("input.txt"))
                .map(Main::validate)
                .filter(Boolean::booleanValue)
                .count();
        System.out.printf("Answer is %s", answer);
    }

    // format: 1-3 a: abcde
    static Boolean validate(String input) {
        final var split = input.split(":");
        final var ruleSplit = split[0].split(" ");
        final var rangeSplit = ruleSplit[0].split("-");
        final var rangeStart = Integer.parseInt(rangeSplit[0]);
        final var rangeEnd = Integer.parseInt(rangeSplit[1]);
        final var ruleCharacter = ruleSplit[1].charAt(0);

        final var characterCounter = input.trim()
                .chars()
                .filter((character) -> character == ruleCharacter)
                .count();

        return characterCounter >= rangeStart && characterCounter <= rangeEnd;
    }

}
