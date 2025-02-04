//AJG23005 中 天花

import java.net.URL;
import java.net.HttpURLConnection;
import java.io.InputStreamReader;
import java.io.BufferedReader;
import java.util.TreeSet;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class Main {
    public static void main(String[] args) {
        try {
            // ターゲットURL
            URL url = new URL("https://www.omu.ac.jp/");
            // 接続オブジェクト
            HttpURLConnection http = (HttpURLConnection) url.openConnection();
            // リクエストメソッドをGETに設定
            http.setRequestMethod("GET");
            // 接続の確立
            http.connect();
            // 文字コード UTF-8 でリーダーを作成
            InputStreamReader isr = new InputStreamReader(http.getInputStream(), "UTF-8");
            // 行単位で読み込む為の準備
            BufferedReader br = new BufferedReader(isr);

            String Content = "";
            String line_buffer;
            while ((line_buffer = br.readLine()) != null) {
                Content += line_buffer;
            }

            // 各々受け持ちクラスを閉じる
            br.close();
            isr.close();
            http.disconnect();

            String target = "href=[\"'](https?://[^\"']+)[\"']";
            Pattern pattern = Pattern.compile(target);
            Matcher matcher = pattern.matcher(Content);

            TreeSet<String> tree_set = new TreeSet<>();

            while (matcher.find()) {
                tree_set.add(matcher.group(1));
            }

            System.out.println("Links in https://www.omu.ac.jp/");

            int index = 1;
            for (String link : tree_set) {
                System.out.println(index + ". " + link);
                index++;
            }

        } catch (Exception e) {}
    }
}
