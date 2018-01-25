package com.gregmaxin.colourmesilly;

import android.os.Bundle;
import android.util.Log;
import android.widget.Button;
import android.widget.GridLayout;
import android.widget.EditText;
import android.widget.ImageButton;
import android.widget.ProgressBar;
import android.widget.TextView;
import android.support.design.widget.FloatingActionButton;
import android.support.design.widget.Snackbar;
import android.support.v7.app.AppCompatActivity;
import android.support.v7.widget.Toolbar;
import android.view.View;
import android.view.Menu;
import android.view.MenuItem;
import android.graphics.Color;


public class MainActivity extends AppCompatActivity {
    String name = "";
    String layout = "Menu";
    int p = 1;
    /** -------------------------------------------------------------------------------------------
    Native Method Declarations
     ------------------------------------------------------------------------------------------- **/
    public native String stringFromJNI(int cmd,int x,int y,int z);


    /** -------------------------------------------------------------------------------------------
     Load Libraries
     ------------------------------------------------------------------------------------------- **/
    static {
        System.loadLibrary("native-lib");
        //System.loadLibrary("Test");
        //System.loadLibrary("Grid.cpp");
        //System.loadLibrary("Cell.cpp");
       // System.loadLibrary("Observer.cpp");
       // System.loadLibrary("Move.cpp");

    }

    /** -------------------------------------------------------------------------------------------
     This is run when the game starts
     ------------------------------------------------------------------------------------------- **/
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        System.out.print("Game Created");
        Toolbar toolbar = (Toolbar) findViewById(R.id.toolbar);
        setSupportActionBar(toolbar);
    }

    /** -------------------------------------------------------------------------------------------
     Gregs Graphical methods
     ------------------------------------------------------------------------------------------- **/
    public void OnClick(View view) {
        EditText editText = findViewById(R.id.Name);

        if (layout == "Game") {
            GridLayout grid = findViewById(R.id.gridLayout);
            int numx = grid.getRowCount();
            int numy = grid.getColumnCount();
            for (int x = 0; x < numx; x++) {
                for (int y = 0; y < numy; y++){
                    Button button = findViewById(getResources().getIdentifier("button" + x + "" + y, "id", this.getPackageName()));

                    if (button != null && button.getId() == view.getId()) {
                        //Log.v("myTag", "WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW");
                        String Display = stringFromJNI(2, x, y, p);
                        UpdateBoard(Display);
                        ProgressBar prog = findViewById(R.id.Progress);;
                        int green = Winner(Display, "G");
                        int red = Winner(Display, "R");
                        if (green > red)
                            prog.setProgress(green);
                        else
                            prog.setProgress(red);
                        if (green == 0 || red == 0) {
                            layout = "Winner";
                            setContentView(R.layout.winner);
                        }

                    }
                }
            }
            for(int i = 1; i < 4; i++){
                ImageButton image = findViewById(getResources().getIdentifier("p" + i, "id", this.getPackageName()));
                if (image != null && image.getId() == view.getId()) {
                    for(int j = 1; j < 4; j++) {
                        ImageButton image2 = findViewById(getResources().getIdentifier("p" + j, "id", this.getPackageName()));
                        image2.setBackgroundColor(Color.WHITE);
                    }
                    image.setBackgroundColor(Color.YELLOW);
                    p = i;
                }

            }
        }
        else if (layout == "Menu") {
            switch (view.getId()) {
                case R.id.Play:
                    name = editText.getText().toString();
                    setContentView(R.layout.game);
                    layout = "Game";
                    String init = stringFromJNI(1, 0, 0, 5);
                    ImageButton startbutton = findViewById(R.id.p1);
                    startbutton.setBackgroundColor(Color.YELLOW);
                    UpdateBoard(init);
                    ProgressBar prog = findViewById(R.id.Progress);
                    prog.setMax(25);
                    int green = Winner(init, "G");
                    int red = Winner(init, "R");
                    if (green > red)
                        prog.setProgress(green);
                    else
                        prog.setProgress(red);

                    break;
                case R.id.Name:
                    editText.getText().clear();
                default:
                    Log.v("myTag", "This is my message");
            }
        }
        else if (layout == "Winner"){

            switch (view.getId()) {
                case R.id.Reset:
                    layout = "Menu";
                    setContentView(R.layout.activity_main);

            }
        }
    }
    public void UpdateBoard(String s){
        //Log.v("myTag", "|||||" + s + "|||||");
        GridLayout grid = findViewById(R.id.gridLayout);
        int numx = grid.getRowCount();
        int numy = grid.getColumnCount();
        char[] arr = s.toCharArray();
        int n = 0;
        for (int x = 0; x < numx; x++) {
            for (int y = 0; y < numy; y++) {
                Button button = findViewById(getResources().getIdentifier("button" + x + "" + y, "id", this.getPackageName()));
                if (arr[n] == 'G')
                    button.setBackgroundColor(Color.GREEN);
                if (arr[n] == 'R')
                    button.setBackgroundColor(Color.RED);
                n++;
            }
        }
    }
    public int Winner(String s, String p){
        char[] arr = s.toCharArray();
        int n = 0;
        int g = 0;
        int r = 0;
        for(int i = 0; i < arr.length; i++){
            if (arr[n] == 'G')
                g++;
            if (arr[n] == 'R')
                r++;
            n++;
        }
        if (p == "G")
            return g;
        else
            return r;
    }
    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        // Inflate the menu; this adds items to the action bar if it is present.
        getMenuInflater().inflate(R.menu.menu_main, menu);
        return true;
    }

    @Override
    public boolean onOptionsItemSelected(MenuItem item) {
        // Handle action bar item clicks here. The action bar will
        // automatically handle clicks on the Home/Up button, so long
        // as you specify a parent activity in AndroidManifest.xml.
        int id = item.getItemId();

        //noinspection SimplifiableIfStatement
        if (id == R.id.action_settings) {
            return true;
        }

        return super.onOptionsItemSelected(item);
    }

}
