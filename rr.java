public void sendMessageToLex(String question) {
    messageList.add(new Message("입력중... ", Message.SENT_BY_BOT, null));

    JSONObject jsonBody = new JSONObject();
    try {
        jsonBody.put("message", question);
    } catch (JSONException e) {
        e.printStackTrace();
    }
    RequestBody requestBody = RequestBody.create(MediaType.parse("application/json"), jsonBody.toString());

    Retrofit retrofit = new Retrofit.Builder()
            .baseUrl("http://18.188.172.219")
            .addConverterFactory(ScalarsConverterFactory.create()) // ScalarsConverter 추가
            .build();

    ApiService apiService = retrofit.create(ApiService.class);

    Call<String> call = apiService.sendMessage(requestBody);
    call.enqueue(new Callback<String>() {
        @Override
        public void onResponse(Call<String> call, Response<String> response) {
            if (response.isSuccessful()) {
                String lexResponse = response.body();
                
                Log.d("Retrofit", "Response: " + lexResponse);
                addResponse(lexResponse);
            } else {
                Log.e("Retrofit", "Request failed: " + response.message());
                addResponse("전송실패 " + response.message());
            }
        }

        @Override
        public void onFailure(Call<String> call, Throwable t) {
            // 통신 실패 처리
            Log.e("Retrofit", "Communication failure: " + t.getMessage());
            addResponse("Communication failure: " + t.getMessage());
        }
    });

}
//