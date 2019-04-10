package com.man.activity;

import java.util.Timer;
import java.util.TimerTask;

import com.example.eat.R;

import android.os.Bundle;
import android.os.Handler;
import android.app.Activity;
import android.content.Intent;
import android.view.View;
import android.view.Window;
import android.view.WindowManager;
import android.view.View.OnClickListener;
import android.widget.Button;

public class MainActivity extends Activity {
	
	private Button skipBtn;
	Timer timer = new Timer();
	
	private int recLen = 5;//����ʱ5s
	private Handler handler;
	private Runnable runnable;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        
        //ȥ��������
        requestWindowFeature(Window.FEATURE_NO_TITLE);
        //����ȫ��
        getWindow().setFlags(WindowManager.LayoutParams.FLAG_FULLSCREEN, WindowManager.LayoutParams.FLAG_FULLSCREEN);
        
        setContentView(R.layout.activity_main);
        
        initView();
        
        timer.schedule(task, 1000, 1000);//ͣ��1��
        
        //���������
        handler = new Handler();
        handler.postDelayed(runnable = new Runnable() {
			
			@Override
			public void run() {
				//����������ҳ��
				Intent intent = new Intent(MainActivity.this, LoginActivity.class);
				startActivity(intent);
				finish();
			}
		},5000);//�ӳ�3�����handler��Ϣ
    }
    
    private void initView(){
    	skipBtn = (Button)findViewById(R.id.skip);
    	skipBtn.setOnClickListener(shipListener);
    }
    
    OnClickListener shipListener = new OnClickListener() {
		
		@Override
		public void onClick(View v) {
			//������������ת���׽���
			Intent intent = new Intent(MainActivity.this, LoginActivity.class);
			startActivity(intent);
			finish();
            if (runnable != null) {
                handler.removeCallbacks(runnable);
            }
		}
	};
    
    TimerTask task = new TimerTask() {
        @Override
        public void run() {
            runOnUiThread(new Runnable() { // UI thread
                @Override
                public void run() {
                    recLen--;
                    skipBtn.setText("���� " + recLen);
                    if (recLen < 0) {
                        timer.cancel();
                        skipBtn.setVisibility(View.GONE);//����ʱ��0��������
                    }
                }
            });
        }
    };

    //�������
    
    
}
