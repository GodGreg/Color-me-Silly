package com.gregmaxin.games;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;

public class Main extends AppCompatActivity {

    // Used to load the 'native-lib' library on application startup.
    static {
        System.loadLibrary("native-lib");
    }
    /** Everything above dun touch **/


    /**
     * A native method that is implemented by the 'native-lib' native library,
     * which is packaged with this application.
     */
    public native String stringFromJNI();

    protected void onCreate(Bundle savedInstanceState) {

        super.onCreate(savedInstanceState);

        setContentView(R.layout.activity_main);
        //setContentView(R.layout.main menu);
        // Example of a call to a native method
        //TextView tv = (TextView) findViewById(R.id.sample_text);
       // tv.setText(Hello());

        final Button button = findViewById(R.id.Square1);

        button.setOnClickListener(new View.OnClickListener() {
            public void onClick(View v) {
                String message = stringFromJNI();

                TextView text = findViewById(R.id.output);
                TextView text2 = findViewById(R.id.sample_text);

                text2.setText(button.getText());
                button.setText(message);
                text.setText(text2.getText());
            }
        });

        public void buttonPress(View v) {
            switch (v.getId()) {
                case R.id.Square1:
                    // We know square1 is (0,0)
                    Array[][] int = Gregcodes(name,3);
                    // 0 1 0 1 0
                    // 1 0 0 0 0
                    break;
                case R.id.button_two:
                    // do something else
                    break;
                case R.id.button_three:
                    // i'm lazy, do nothing
                    break;
            }
        }



    }
}
